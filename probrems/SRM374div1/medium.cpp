#include <algorithm>
#include <sstream>
#include <string>
#include <stack>
#include <utility>
#include <vector>
#include <iostream>

using namespace std;

class PlayerExtraction
{
	public:

		int bottom,ceil,left,right,S,h,w,k;
		vector<string> photo;
		
		void show()
		{
			for(int i=0;i<h;i++)
				cout << photo[i] << endl;
			cout << endl;
		}

		void calc(int startY,int startX)
		{
			bottom=(1<<28),ceil=-1,left=(1<<28),right=-1,S=0;
			int mv[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
			stack<pair<int,int> > sta;
			sta.push(make_pair(startY,startX));

			while(!sta.empty())
			{
				int y=sta.top().first,x=sta.top().second;
				sta.pop();
				if(photo[y][x]!='0'+k)
					continue;

				bottom=min(bottom,y),ceil=max(ceil,y);
				left=min(left,x),right=max(right,x);
				S++;
				photo[y][x]='s';

				for(int i=0;i<4;i++)
				{
					int yy=y+mv[i][0],xx=x+mv[i][1];
					if(0<=yy && yy<h && 0<=xx && xx<w)
						sta.push(make_pair(yy,xx));
				}
			}
			return;
		}

		vector<string> extractPlayers(vector<string> _photo,int _k,int threshold)
		{
			photo=_photo;
			h=photo.size(),w=photo[0].size(),k=_k;
			vector<pair<int,int> > tmp;

			for(int y=0;y<h;y++)
				for(int x=0;x<w;x++)
				{
					if(photo[y][x]=='0'+k)
					{
						calc(y,x);
						
						show();
						
						if(threshold<=S*4)
						{
							ceil++,right++;
							tmp.push_back(make_pair(left+right,bottom+ceil));
						}
					}
				}
			sort(tmp.begin(),tmp.end());
			vector<string> ans;
			for(int i=0;i<(int)tmp.size();i++)
			{
				stringstream ss;
				ss << tmp[i].first << " " << tmp[i].second;
				ans.push_back(ss.str());
			}

			return ans;
		}
};


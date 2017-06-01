#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

class PiecesMover
{
	public:

		int n;
		vector<int> pos;

		int DFS(set<int> se,vector<int> p)
		{
			//printf("p.size()=%d\n",p.size());
			int r=(1<<28);

			if(p.size()==n)
			{
				sort(p.begin(),p.end());
				do{
					int a=0;
					for(int i=0;i<n;i++)
					{
						int fx,tx,fy,ty;
						fy=pos[i]/5,fx=pos[i]%5;
						ty=p[i]/5,tx=p[i]%5;
						a+=(int)abs(fy-ty)+(int)abs(fx-tx);
					}
					r=min(a,r);
				}while(next_permutation(p.begin(),p.end()));
			}
			else
			{
				int mv[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
				set<int>::iterator itr;
				for(itr=se.begin();itr!=se.end();itr++)
					if(find(p.begin(),p.end(),(*itr)) == p.end())
					{
						vector<int> q=p;
						q.push_back((*itr));
						set<int> te=se;
						int y=(*itr)/5,x=(*itr)%5;
						for(int i=0;i<4;i++)
						{
							int yy=y+mv[i][0],xx=x+mv[i][1];
							if(0<=yy && yy<5 && 0<=xx && xx<5)
								te.insert(yy*5+xx);
						}

						r=min(r,DFS(te,q));
					}
			}

			return r;
		}

		int getMinimumMoves(vector<string> board)
		{
			n=0;
			for(int i=0;i<5;i++)
				for(int j=0;j<5;j++)
					if(board[i][j]=='*')
					{
						pos.push_back(i*5+j);
						n++;
					}

			int ans=(1<<28);
			for(int i=0;i<25;i++)
			{
				int mv[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
				set<int> se;
				vector<int> v;
				se.insert(i);
				v.push_back(i);
				for(int j=0;j<4;j++)
				{
					int yy=i/5+mv[j][0],xx=i%5+mv[j][1];
					if(0<=yy && yy<5 && 0<=xx && xx<5)
						se.insert(yy*5+xx);
				}

				ans=min(ans,DFS(se,v));
			}
			return ans;
		}
};


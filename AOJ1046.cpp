#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

int mv[5][2]={{-1,0},{0,-1},{1,0},{0,1},{0,0}};

int main()
{
	while(1){
		int h,w,gy,gx,p=0,time;
		string pat;
		vector<string> town;
		stack<pair<int,int> > sta;
		cin>>h>>w;
		if(h==0 && w==0)
			break;
		for(int i=0;i<h;i++){
			string s;
			cin>>s;
			for(int j=0;j<w;j++)
				if(s[j]=='B')
					gy=i,gx=j,s[j]='.';
				else if(s[j]=='A')
					sta.push(make_pair(i,j));
			town.push_back(s);
		}
		cin>>pat;
		for(time=0;time<500;time++){
			if(town[gy][gx]=='A')
				break;
			stack<pair<int,int> > st;
			while(!sta.empty()){
				int y=sta.top().first;
				int x=sta.top().second;
				sta.pop();
				for(int i=0;i<5;i++){
					int yy=y+mv[i][0];
					int xx=x+mv[i][1];
					if(0<=yy && yy<h && 0<=xx && xx<w && town[yy][xx]=='.'){
						town[yy][xx]='A';
						st.push(make_pair(yy,xx));
					}
				}
			}
			sta=st;
			if(pat[p]=='5')
				;
			else if(pat[p]=='8' && 0<gy)
				gy--;
			else if(pat[p]=='6' && gx<w-1)
				gx++;
			else if(pat[p]=='4' && 0<gx)
				gx--;
			else if(pat[p]=='2' && gy<h-1)
				gy++;
			p=(p+1)%(int)pat.size();
		}
		if(time!=500)
			cout<<time<<" "<<gy<<" "<<gx<<endl;
		else
			cout<<"impossible"<<endl;
	}
	return 0;
}


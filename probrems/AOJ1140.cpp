//AOJ1140
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct V{int y,x,s,d;};
V makeV(int i,int j,int k,int l){V v;v.y=i;v.x=j;v.s=k;v.d=l;return v;}
bool operator < (const V &v,const V &u){return v.d>u.d;}
int mv[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int D[1<<10][20][20];
int main(){
	while(1){
		for(int i=0;i<1<<10;i++)for(int j=0;j<20;j++)for(int k=0;k<20;k++)
			D[i][j][k]=10000;
		int w,h,m=0,ans=10000;
		cin>>w>>h;
		if(!w)	break;
		vector<string> fl(h);
		for(int i=0;i<h;i++)	cin>>fl[i];
		map<int,int> ma;
		priority_queue<V> que;
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				if(fl[i][j]=='*'){
					ma[i*w+j]=m;
					m++;
				}else if(fl[i][j]=='o'){
					que.push(makeV(i,j,0,0));
					fl[i][j]='.';
				}
		while(!que.empty()){
			V v=que.top();que.pop();
			int y=v.y,x=v.x,s=v.s,d=v.d;
			if(D[s][y][x]<=d)	continue;
			D[s][y][x]=d;
			if(fl[y][x]=='*')
				que.push(makeV(y,x,s|(1<<ma[y*w+x]),d));
			for(int i=0;i<4;i++){
				int yy=y+mv[i][0],xx=x+mv[i][1];
				if(0<=yy&&yy<h&&0<=xx&&xx<w&&fl[yy][xx]!='x')
					que.push(makeV(yy,xx,s,d+1));
			}
		}
		for(int i=0;i<h;i++)for(int j=0;j<w;j++)ans=min(ans,D[(1<<m)-1][i][j]);
		if(ans==10000)	cout<<-1<<endl;
		else			cout<<ans<<endl;
	}
	return 0;
}


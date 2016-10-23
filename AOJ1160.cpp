//AOJ1160
#include <stdio.h>
#include <queue>
using namespace std;
int mv[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int ch[50][50];
int main(){
	while(1){
		int w,h;
		scanf("%d%d",&w,&h);
		if(!w&&!h)	break;
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				scanf("%d",&ch[i][j]);
		int ans=0;
		for(int sy=0;sy<h;sy++)
			for(int sx=0;sx<w;sx++)
				if(ch[sy][sx]==1){
					ans++;
					queue<int> que;
					que.push(sy*w+sx);
					while(!que.empty()){
						int y=que.front()/w;
						int x=que.front()%w;
						que.pop();
						if(ch[y][x]!=1)	continue;
						ch[y][x]=2;
						for(int i=0;i<8;i++){
							int yy=y+mv[i][0];
							int xx=x+mv[i][1];
							if(0<=yy&&yy<h&&0<=xx&&xx<w)
								que.push(yy*w+xx);
						}
					}
				}
		printf("%d\n",ans);
	}
	return 0;
}


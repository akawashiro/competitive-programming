//AOJ0118
#include <stdio.h>
#include <queue>
#include <map>
using namespace std;
int mv[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char grove[100][100];
int main()
{
	while(1){
		int h,w;
		scanf("%d%d",&h,&w);
		if(!h&&!w)
			break;
		for(int i=0;i<h;i++)
			scanf("%s",grove[i]);
		int ans=0;
		for(int sy=0;sy<h;sy++)
			for(int sx=0;sx<w;sx++)
				if(grove[sy][sx]!='a'){
					ans++;
					char c=grove[sy][sx];
					queue<pair<int,int> > que;
					que.push(make_pair(sy,sx));
					while(!que.empty()){
						int y=que.front().first;
						int x=que.front().second;
						que.pop();
						if(y<0||h<=y||x<0||w<=x||grove[y][x]!=c)
							continue;
						grove[y][x]='a';
						for(int i=0;i<4;i++)
							que.push(make_pair(y+mv[i][0],x+mv[i][1]));
					}
				}
		printf("%d\n",ans);
	}
	return 0;
}



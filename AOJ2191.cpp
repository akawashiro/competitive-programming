//AOJ2191
#include <stdio.h>
#include <queue>
#include <map>
#include <string.h>
#define MP make_pair
using namespace std;
int x[1000];
int y[1000];
int last[1000];
int G[1000][1000];
int main(){
	int T;
	scanf("%d",&T);
	for(;0<T;T--){
		int n,X,Y;
		scanf("%d%d%d",&n,&X,&Y);
		int sx,sy;
		scanf("%d%d",&sx,&sy);
		for(int i=0;i<n;i++)
			scanf("%d%d",x+i,y+i);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(i==j)	G[i][j]=0;
				else	G[i][j]=((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<=2500);
		queue<pair<int,int> > que;
		for(int i=0;i<n;i++)
			if((x[i]-sx)*(x[i]-sx)+(y[i]-sy)*(y[i]-sy)<=100)
				que.push(MP(X,i));
		int v=0;
		memset(last,0,sizeof(last));
		for(int c=0;c<1000*1000&&!que.empty();c++){
			int t=que.front().first;
			int k=que.front().second;
			que.pop();
			if(last[k]==0||Y<(t-X)-last[k]){
				last[k]=t;
				v=t;
				for(int i=0;i<n;i++)
					if(G[k][i])
						que.push(MP(t+X,i));
			}
		}
		if(!que.empty())
			printf("You're always welcome!\n");
		else
			printf("%d\n",v);
	}
	return 0;
}


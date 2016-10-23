#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <map>
#define INF 10000
using namespace std;
int n;
int up[1<<25];
int dist[1<<25];
int ene[5][5];
int encode(){
	int r=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(ene[i][j])
				r+=(1<<(i*n+j));
	return r;
}
int main(){
	for(int i=0;i<1<<25;i++){
		int j;
		for(j=0;j<25;j++)
			if(i&(1<<j))
				break;
		up[i]=j;
	}
	while(1){
		scanf("%d",&n);
		if(!n)	break;
		memset(ene,0,sizeof(ene));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				scanf("%d",&ene[i][j]);
			}
		queue<pair<int,int> > que;
		que.push(make_pair(0,encode()));
		vector<int> v[25];
		for(int i=0;i<n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=0;k<n;k++)
					for(int l=k+1;l<=n;l++){
						memset(ene,0,sizeof(ene));
						for(int y=i;y<j;y++)
							for(int x=k;x<l;x++){
								ene[y][x]=1;
							}
						int e=encode();
						v[up[e]].push_back(e);
						//printf("--%d\n",v.back());
					}
		for(int i=0;i<1<<25;i++)
			dist[i]=INF;
		while(!que.empty()){
			int d=que.front().first;
			int s=que.front().second;
			que.pop();
			if(dist[s]<d)	continue;
			dist[s]=d;
			if(s==0)	break;
			int u=up[s];
			for(int i=0;i<(int)v[u].size();i++)
				if(d+1<dist[s^v[u][i]]){
					dist[s^v[u][i]]=d+1;
					que.push(make_pair(d+1,s^v[u][i]));
				}
		}
		printf("%d\n",dist[0]);
	}
	return 0;
}


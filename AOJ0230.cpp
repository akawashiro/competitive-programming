//AOJ0230
#include <stdio.h>
#include <queue>
#include <map>
#include <vector>
#include <functional>
#define INF 10000
#define MP make_pair
int wall[2][200];
int dist[2][200];
using namespace std;
typedef pair<int,int> P;
int main(){
	while(1){
		int n;
		scanf("%d",&n);
		if(!n)	break;
		for(int i=0;i<2;i++)
			for(int j=0;j<n;j++){
				scanf("%d",&wall[i][j]);
				dist[i][j]=INF;
			}
		priority_queue<P,vector<P>,greater<P> > que;
		que.push(MP(0,0*2+0));
		que.push(MP(0,0*2+1));
		while(!que.empty()){
			int d=que.top().first;
			int y=que.top().second/2;
			int w=que.top().second%2;
			que.pop();
			if(d<dist[w][y]){
				int ww=(w)?0:1;
				if(!(wall[w][y]==2&&n-1<=y))
					dist[w][y]=d;
				if(n-1<=y){
				}else if(wall[w][y]==0||(wall[w][y]==1&&wall[w][y+1]!=1)){
					que.push(MP(d+1,y*2+ww));
					que.push(MP(d+1,(y+1)*2+ww));
					que.push(MP(d+1,(y+2)*2+ww));
				}else if(wall[w][y]==1){
					que.push(MP(d,(y+1)*2+w));
				}else{
					que.push(MP(d,(y-1)*2+w));
				}
			}
		}
		int ans=min(dist[0][n-1],dist[1][n-1]);
		if(ans==INF)
			printf("NA\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}


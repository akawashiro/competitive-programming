//AOJ1166
#include <stdio.h>
#include <queue>
#include <map>
#include <vector>
#define INF 10000
using namespace std;
int dist[1000];
vector<int> G[1000];
int main(){
	while(1){
		int h,w;
		scanf("%d%d",&w,&h);
		if(!w)	
			break;
		for(int i=0;i<1000;i++){
			dist[i]=INF;
			G[i].clear();
		}
		for(int i=0;i<2*h-1;i++){
			int y=i/2;
			if(i%2==0){
				for(int x=0;x<w-1;x++){
					int a;
					scanf("%d",&a);
					if(!a){
						int yy=y,xx=x+1;
						//printf("y=%d x=%d yy=%d xx=%d\n",y,x,yy,xx);
						G[y*w+x].push_back(yy*w+xx);
						G[yy*w+xx].push_back(y*w+x);
					}
				}
			}else{
				for(int x=0;x<w;x++){
					int a;
					scanf("%d",&a);
					if(!a){
						int yy=y+1,xx=x;
						//printf("y=%d x=%d yy=%d xx=%d\n",y,x,yy,xx);
						G[y*w+x].push_back(yy*w+xx);
						G[yy*w+xx].push_back(y*w+x);
					}
				}
			}
		}
		queue<pair<int,int> > que;
		que.push(make_pair(1,0));
		while(!que.empty()){
			int d=que.front().first;
			int p=que.front().second;
			que.pop();
			//printf("d=%d p=%d\n",d,p);
			if(d<dist[p]){
				dist[p]=d;
				for(int i=0;i<(int)G[p].size();i++)
					que.push(make_pair(d+1,G[p][i]));
			}
		}
		if(dist[h*w-1]!=INF)
			printf("%d\n",dist[h*w-1]);
		else
			printf("0\n");
	}
	return 0;
}



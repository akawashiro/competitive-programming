//AOJ0122
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <queue>
using namespace std;
int mv[12][2]={{-2,1},{-2,0},{-2,-1},{2,1},{2,0},{2,-1},{-1,2},{0,2},{1,2},{-1,-2},{0,-2},{1,-2}};
int main()
{
	while(1){
		int px,py,n;
		int sp[10][2];
		scanf("%d%d",&px,&py);
		if(!px&&!py)
			break;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d%d",&sp[i][0],&sp[i][1]);
		queue<pair<int,int> > que;
		que.push(make_pair(px,py));
		for(int i=0;i<n;i++){
			queue<pair<int,int> > nex;
			while(!que.empty()){
				px=que.front().first,py=que.front().second;
				que.pop();
				//printf("px=%d py=%d\n",px,py);
				for(int j=0;j<12;j++){
					int x=px+mv[j][0],y=py+mv[j][1];
					//printf("x=%d y=%d\n",x,y);
					if(0<=x&&x<10&&0<=y&&y<10&&abs(x-sp[i][0])<2&&abs(y-sp[i][1])<2){
						//printf("x=%d y=%d\n",x,y);
						nex.push(make_pair(x,y));
					}
				}
			}
			que=nex;
		}
		if(que.empty())
			printf("NA\n");
		else
			printf("OK\n");
	}
	return 0;
}


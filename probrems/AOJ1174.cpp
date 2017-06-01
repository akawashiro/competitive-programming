//AOJ1174 
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int h,w;
int mv[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
vector<vector<int> > origin;
vector<vector<int> > board;
void change(int c){
	queue<int> yq,xq;
	int o=board[0][0];
	yq.push(0);	xq.push(0);
	while(!yq.empty()){
		int y=yq.front(),x=xq.front();
		//printf("y=%d x=%d\n",y,x);
		yq.pop(),xq.pop();
		if(board[y][x]!=o){
			//printf("y=%d x=%d\n",y,x);
			continue;
		}
		board[y][x]=10;
		for(int i=0;i<4;i++){
			int yy=y+mv[i][0],xx=x+mv[i][1];
			if(0<=yy&&yy<h&&0<=xx&&xx<w&&board[yy][xx]==o)
				yq.push(yy),xq.push(xx);
		}
	}
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			if(board[i][j]==10)
				board[i][j]=c;
}
int count(){
	queue<int> yq,xq;
	int o=board[0][0];
	int res=0;
	yq.push(0);	xq.push(0);
	while(!yq.empty()){
		int y=yq.front(),x=xq.front();
		yq.pop(),xq.pop();
		if(board[y][x]!=o)
			continue;
		board[y][x]=10;
		for(int i=0;i<4;i++){
			int yy=y+mv[i][0],xx=x+mv[i][1];
			if(0<=yy&&yy<h&&0<=xx&&xx<w&&board[yy][xx]==o)
				yq.push(yy),xq.push(xx);
		}
	}
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++){
			if(board[i][j]==10){
				res++;
				board[i][j]=o;
			}
		}
	return res;
}
void show(){
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++)
			printf("%d ",board[i][j]);
		printf("\n");
	}
	printf("\n");
}
int main(){
	while(1){
		origin.clear();
		board.clear();
		int c;
		scanf("%d%d%d",&h,&w,&c);
		if(!h&&!w&&!c)
			break;
		for(int i=0;i<h;i++){
			vector<int> v;
			for(int j=0;j<w;j++){
				int a;
				scanf("%d",&a);
				v.push_back(a);
			}
			origin.push_back(v);
		}
		int ans=0;
		for(int m=0;m<1296;m++){
			vector<int> w;
			int mm=m;
			for(int i=0;i<4;i++){
				w.push_back(mm%6+1);
				mm/=6;
			}
			w.push_back(c);
			board=origin;
			for(int i=0;i<5;i++){
				change(w[i]);
				//printf("change %d \n",w[i]);
				//show();
			}
			ans=max(ans,count());
		}
		printf("%d\n",ans);
	}
	return 0;
}


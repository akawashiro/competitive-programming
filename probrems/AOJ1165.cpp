//AOJ1165
#include <stdio.h>
#include <algorithm>
using namespace std;
int x[200];
int y[200];
int mv[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int main(){
	while(1){
		int n;
		scanf("%d",&n);
		if(!n)
			break;
		x[0]=y[0]=0;
		for(int i=1;i<n;i++){
			int k,d;
			scanf("%d%d",&k,&d);
			x[i]=x[k]+mv[d][0];
			y[i]=y[k]+mv[d][1];
		}
		int xa=-1000,xi=1000,ya=-1000,yi=1000;
		for(int i=0;i<n;i++){
			xa=max(xa,x[i]);
			xi=min(xi,x[i]);
			ya=max(ya,y[i]);
			yi=min(yi,y[i]);
		}
		printf("%d %d\n",xa-xi+1,ya-yi+1);
	}
	return 0;
}



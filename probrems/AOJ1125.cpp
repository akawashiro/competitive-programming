//AOJ1125
#include <stdio.h>
#include <string.h>
int sum[100][100];
int fie[100][100];
int main(){
	while(1){
		memset(sum,0,sizeof(sum));
		memset(fie,0,sizeof(fie));
		int n,w,h;
		scanf("%d",&n);
		if(!n)	break;
		scanf("%d%d",&w,&h);
		for(int i=0;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;
			fie[y][x]++;
		}
		for(int i=0;i<h;i++){
			int a=0;
			for(int j=0;j<w;j++){
				a+=fie[i][j];
				sum[i][j]=a;
				if(0<i)
					sum[i][j]+=sum[i-1][j];
			}
		}
		int s,t,ans=0;
		scanf("%d%d",&s,&t);
		for(int i=0;i+t<=h;i++)
			for(int j=0;j+s<=w;j++){
				int a=sum[i+t-1][j+s-1];
				if(0<i)	a-=sum[i-1][j+s-1];
				if(0<j)	a-=sum[i+t-1][j-1];
				if(0<i&&0<j)	a+=sum[i-1][j-1];
				if(ans<a)
					ans=a;
			}
		printf("%d\n",ans);
	}
	return 0;
}


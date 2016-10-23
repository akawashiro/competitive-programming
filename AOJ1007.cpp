//AOJ1007
#include <stdio.h>
int gr[10][10];
int main(){
	for(int t=1;;t++){
		int n;
		scanf("%d",&n);
		if(!n)
			break;
		int y=0,x=0;
		int my=-1,mx=1;
		for(int c=0;c<n*n;c++){
			gr[y][x]=c+1;
			int yy=y+my,xx=x+mx;
			if(0<=yy&&yy<n&&0<=xx&&xx<n)
				y=yy,x=xx;
			else{
				y=yy,x=xx;
				my=-my,mx=-mx;
				if(y==-1)	y=0;
				else if(x==-1)	x=0;
				else if(y==n)	y=n-1,x+=2;
				else if(x==n)	x=n-1,y+=2;
				else			;
				if(x<0||n<=x||y<0||n<=y)	y+=my,x+=mx;
			}
		}
		printf("Case %d:\n",t);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				printf("%3d",gr[i][j]);
			printf("\n");
		}
	}
	return 0;
}


//AOJ2186
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long LL;
int xw[20][20];
int yw[20][20];
LL  w[20][20];
int main()
{
	int T;
	scanf("%d",&T);
	for(;0<T;T--){
		int gx,gy,p;
		scanf("%d%d%d",&gx,&gy,&p);
		for(int i=0;i<=gx;i++)
			for(int j=0;j<=gy;j++)
				xw[j][i]=1,yw[i][j]=1,w[i][j]=0;
		for(int i=0;i<p;i++){
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			if(x1==x2)
				for(int y=min(y1,y2);y<max(y1,y2);y++)
					yw[x1][y]=0;
			else
				for(int x=min(x1,x2);x<max(x1,x2);x++)
					xw[y1][x]=0;
		}
		for(int i=0;i<=gx;i++)
			for(int j=0;j<=gy;j++)
				if(i==0 && j==0)
					w[i][j]=1;
				else{
					if(0<i && xw[j][i-1])
						w[i][j]+=w[i-1][j];
					if(0<j && yw[i][j-1])
						w[i][j]+=w[i][j-1];
				}
		if(w[gx][gy]==0)
			printf("Miserable Hokusai!\n");
		else
			printf("%lld\n",w[gx][gy]);
	}
	return 0;
}



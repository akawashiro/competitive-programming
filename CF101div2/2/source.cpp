#include <stdio.h>
int lc[4][2]={{-1,0},{-1,2},{-2,4},{0,4}};
int main(){
	int a,x,y;
	scanf("%d%d%d",&a,&x,&y);
	x*=2,y*=2;
	for(int i=0;i<4;i++)
		for(int j=0;j<2;j++)
			lc[i][j]*=a;
	a*=2;
	int ans=-1;
	for(int i=0;i<4;i++)
		if(lc[i][0]<x&&x<lc[i][0]+a&&lc[i][1]<y&&y<lc[i][1]+a)
			ans=i+1;
	int offset=4;
	while(lc[1][1]<y){
		//printf("lc[1][1]=%d\n",lc[1][1]);
		for(int i=1;i<4;i++)
			lc[i][1]+=2*a;
		//printf("lc[1][1]=%d\n",lc[1][1]);
		for(int i=1;i<4;i++)
			if(lc[i][0]<x&&x<lc[i][0]+a&&lc[i][1]<y&&y<lc[i][1]+a){
				//printf("lc[%d][0]=%d lc[%d][1]=%d\n",i,lc[i][0],i,lc[i][1]);
				//printf("i=%d\n",i);
				ans=offset+i;
			}
		offset+=3;
	}
	printf("%d\n",ans);
	return 0;
}


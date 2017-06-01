#include <stdio.h>
#include <algorithm>

using namespace std;

int cost[1000+10][1000+10];
int people[1000+10][1000+10];
int cSum[1000+10][1000+10];
int pSum[1000+10][1000+10];

int main()
{
	int h,w,height,width;
	scanf("%d%d%d%d",&w,&h,&width,&height);
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
		{
			int t;
			scanf("%d",&t);
			cost[i][j]=0,people[i][j]=0;
			if(t!=-1)
				cost[i][j]=t;
			else
				people[i][j]=1;
		}
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
		{
			cSum[i][j]=0;
			pSum[i][j]=0;
			if(0<i)
			{
				cSum[i][j]+=cSum[i-1][j];
				pSum[i][j]+=pSum[i-1][j];
			}
			if(0<j)
			{
				cSum[i][j]+=cSum[i][j-1];
				pSum[i][j]+=pSum[i][j-1];
			}
			if(0<i && 0<j)
			{
				cSum[i][j]-=cSum[i-1][j-1];
				pSum[i][j]-=pSum[i-1][j-1];
			}
			cSum[i][j]+=cost[i][j];
			pSum[i][j]+=people[i][j];
		}
	int ans=1000*1000*100;
	for(int i=height-1;i<h;i++)
		for(int j=width-1;j<w;j++)
		{
			int cT=cSum[i][j],pT=pSum[i][j];
			if(0<=i-height)
			{
				cT-=cSum[i-height][j];
				pT-=pSum[i-height][j];
			}
			if(0<=j-width)
			{
				cT-=cSum[i][j-width];
				pT-=pSum[i][j-width];
			}
			if(0<=i-height && 0<=j-width)
			{
				cT+=cSum[i-height][j-width];
				pT+=pSum[i-height][j-width];
			}
			if(pT==0)
				ans=min(ans,cT);
		}
	printf("%d\n",ans);
	return 0;
}


#include <stdio.h>
#include <algorithm>

using namespace std;

int cost[100+20][100+20];
int time[100+20][100+20];

int main()
{
	while(1)
	{
		for(int i=0;i<100+10;i++)
			for(int j=0;j<100+10;j++)
				cost[i][j]=time[i][j]=1000*1000;
		for(int i=0;i<100+10;i++)
			cost[i][i]=time[i][i]=0;
		int n;
		{
			int r;
			scanf("%d%d",&r,&n);
			if(r==0 && n==0)
				break;
			for(int i=0;i<r;i++)
			{
				int a,b,c,t;
				scanf("%d%d%d%d",&a,&b,&c,&t);
				cost[a][b]=cost[b][a]=c;
				time[a][b]=time[b][a]=t;
			}
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
				{
					cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
					time[i][j]=min(time[i][j],time[i][k]+time[k][j]);
				}
		{
			int k;
			scanf("%d",&k);
			for(int i=0;i<k;i++)
			{
				int p,q,r;
				scanf("%d%d%d",&p,&q,&r);
				if(r==0)
					printf("%d\n",cost[p][q]);
				else
					printf("%d\n",time[p][q]);
			}
		}
	}
	return 0;
}


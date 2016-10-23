#include <stdio.h>

int price[370][3000+10];
int DP[370][3000+10][4];

void checkMin(int &a,int b)
{
	if(b<a)
		a=b;
}

int main()
{
	int N,D;
	scanf("%d%d",&N,&D);
	for(int i=0;i<D;i++)
		for(int j=0;j<N;j++)
			scanf("%d",&price[i][j]);
	for(int d=0;d<=D;d++)
		for(int i=0;i<N;i++)
			for(int c=0;c<3;c++)
				DP[d][i][c]=100000*365;
	for(int i=0;i<N;i++)
		DP[0][i][0]=0;
	for(int d=0;d<D;d++)
	{
		int minC0=100000*365;
		for(int i=0;i<N;i++)
			for(int c=0;c<3;c++)
			{
				if(c==0)
				{
					checkMin(DP[d+1][i][c+1],DP[d][i][c]+price[d][i]);
					checkMin(minC0,DP[d][i][c]+price[d][i]);
				}
				else if(c==1)
				{
					checkMin(DP[d+1][i][c+1],DP[d][i][c]+price[d][i]/10*9);
					checkMin(minC0,DP[d][i][c]+price[d][i]/10*9);
				}
				else if(c==2)
				{
					checkMin(DP[d+1][i][2],DP[d][i][c]+price[d][i]/10*7);
					checkMin(minC0,DP[d][i][c]+price[d][i]/10*7);
				}
				/*else if(c==3)
				{
					checkMin(DP[d+1][i][3],DP[d][i][c]+price[d][i]/10*7);
					checkMin(minC0,DP[d][i][c]+price[d][i]/10*7);
				}*/
			}
		for(int i=0;i<N;i++)
			DP[d+1][i][0]=minC0;
	}
	/*for(int d=0;d<D;d++)
		for(int i=0;i<N;i++)
			for(int c=0;c<3;c++)
				printf("DP[%d][%d][%d]=%d\n",d,i,c,DP[d][i][c]);*/
	int ans=100000*365;
	for(int i=0;i<N;i++)
		for(int c=0;c<3;c++)
			checkMin(ans,DP[D][i][c]);
	printf("%d\n",ans);
	return 0;
}


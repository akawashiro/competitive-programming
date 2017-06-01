#include <stdio.h>
#include <algorithm>

using namespace std;

int snack[10000+10];
int DP[2][10000+10][2];

void checkMin(int &a,int b)
{
	a=min(a,b);
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
		scanf("%d",snack+i);
	for(int A=0;A<=n/2;A++)
		for(int isA=0;isA<2;isA++)
			DP[0][A][isA]=10000+10;
	DP[0][1][1]=0,DP[0][0][0]=0;
	for(int pos=0;pos<n-1;pos++)
	{
		for(int A=0;A<=n/2;A++)
			for(int isA=0;isA<2;isA++)
				DP[(pos+1)%2][A][isA]=10000+10;
		for(int A=0;A<=n/2;A++)
			for(int isA=0;isA<2;isA++)
			{
				//printf("DP[%d][%d][%d]=%d\n",pos,A,isA,DP[pos%2][A][isA]);
				int now=DP[pos%2][A][isA];
				if(isA)
				{
					checkMin(DP[(pos+1)%2][A+1][1],now);
					checkMin(DP[(pos+1)%2][A][0],now+snack[pos]);
				}
				else
				{
					checkMin(DP[(pos+1)%2][A][0],now);
					checkMin(DP[(pos+1)%2][A+1][1],now+snack[pos]);
				}
			}
	}
	int ans=min(DP[(n-1)%2][n/2][0],DP[(n-1)%2][n/2][1]);
	printf("%d\n",ans);
	return 0;
}


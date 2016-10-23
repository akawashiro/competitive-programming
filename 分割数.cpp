#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	int dp[51][51];

	for(int i=0;i<=50;i++)
		for(int j=0;j<=50;j++)
		{
			if(i==0 && j==0)
				dp[i][j]=1;
			else
			{
				dp[i][j]=0;
				if(0<=i-j)
					dp[i][j]+=dp[i-j][j];
				if(0<=j-1)
					dp[i][j]+=dp[i][j-1];
			}
		}

	for(int i=1;i<=50;i++)
		printf("P%3d = %5d\n",i,dp[i][i]);

	return 0;
}


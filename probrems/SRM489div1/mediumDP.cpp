#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	int DP[25][25][6];
	memset(DP,0,sizeof(DP));
	DP[1][0][4]=1;
	DP[0][1][2]=1;
	DP[0][0][0]=1;
	for(int i=0;i<20;i++)
		for(int j=0;j<20;j++)
		{
			DP[i+1][j][0]+=DP[i][j][1];
			DP[i][j+1][1]+=DP[i][j][1];

			DP[i+1][j][2]+=DP[i][j][2];
			DP[i][j+1][5]+=DP[i][j][2];

			DP[i+1][j][3]+=DP[i][j][3];
			DP[i][j+1][0]+=DP[i][j][3];

			DP[i+1][j][5]+=DP[i][j][4];
			DP[i][j+1][4]+=DP[i][j][4];

			DP[i+1][j][1]+=DP[i][j][5];
			DP[i][j+1][3]+=DP[i][j][5];
		}

	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
			printf("%5d",DP[i][j][0]);
		printf("\n");
	}
	return 0;
}


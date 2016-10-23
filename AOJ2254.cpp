//AOJ2254
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
using namespace std;

int n;
int t[16][17];
int DP[1<<16];

int main()
{
	while(1){
		scanf("%d",&n);
		if(!n)
			break;
		for(int i=0;i<n;i++)
			for(int j=0;j<n+1;j++)
				scanf("%d",&t[i][j]);
		for(int m=1;m<1<<n;m++)
			DP[m]=INT_MAX/2;
		DP[0]=0;
		for(int m=0;m<1<<n;m++){
			for(int i=0;i<n;i++)
				DP[m|(1<<i)]=min(DP[m|(1<<i)],DP[m]+t[i][0]);
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(m&(1<<j))
						DP[m|(1<<i)]=min(DP[m|(1<<i)],DP[m]+t[i][j+1]);
		}
		printf("%d\n",DP[(1<<n)-1]);
	}
	return 0;
}


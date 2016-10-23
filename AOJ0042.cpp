#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int weight[1000+10];
int value[1000+10];
int DP[1000+10][2000+10];

int main()
{
	for(int time=1;;time++)
	{
		int N,W;
		scanf("%d",&W);
		if(W==0)
			break;
		scanf("%d",&N);
		for(int i=0;i<N;i++)
			scanf("%d,%d",value+i,weight+i);
		memset(DP,-1,sizeof(DP));
		DP[0][0]=0;
		for(int i=0;i<N;i++)
			for(int w=0;w<=W;w++)
				if(DP[i][w]!=-1)
				{
					DP[i+1][w+weight[i]]=max(DP[i+1][w+weight[i]],DP[i][w]+value[i]);
					DP[i+1][w]=max(DP[i+1][w],DP[i][w]);
				}
		int ansVal=0,ansWei=0;
		for(int w=0;w<=W;w++)
			if(ansVal<DP[N][w])
			{
				ansVal=DP[N][w];
				ansWei=w;
			}
		printf("Case %d:\n",time);
		printf("%d\n",ansVal);
		printf("%d\n",ansWei);
	}
	return 0;
}


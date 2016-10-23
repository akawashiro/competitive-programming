//AOJ0154
#include <stdio.h>
#include <string.h>
int DP[8][3000];
int main()
{
	while(1){
		int m;
		int a[7],b[7];
		scanf("%d",&m);
		if(!m)
			break;
		for(int i=0;i<m;i++)
			scanf("%d%d",a+i,b+i);
		memset(DP,0,sizeof(DP));
		DP[0][0]=1;
		for(int i=0;i<m;i++)
			for(int j=0;j<1500;j++)
				for(int k=0;k<=b[i];k++)
					DP[i+1][j+a[i]*k]+=DP[i][j];
		int g;
		scanf("%d",&g);
		for(int i=0;i<g;i++){
			int n;
			scanf("%d",&n);
			printf("%d\n",DP[m][n]);
		}
	}
	return 0;
}


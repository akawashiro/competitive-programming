#include <stdio.h>
typedef long long LL;
LL DP[31];

int main()
{
	DP[0]=1;
	for(int i=1;i<31;i++)
		for(int j=i-1;i-3<=j && 0<=j;j--)
			DP[i]+=DP[j];
	while(1){
		int n;
		scanf("%d",&n);
		if(!n)
			break;
		printf("%lld\n",(DP[n]+3649)/(LL)3650);
	}
	return 0;
}


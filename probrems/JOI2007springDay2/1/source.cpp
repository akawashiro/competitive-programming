#include <stdio.h>
#include <algorithm>

using namespace std;

int building[1000+10];
int DP[1000+10];

int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",building+i);
	for(int i=0;i<n;i++)
	{
		DP[i]=0;
		for(int j=0;j<i;j++)
			if(building[j]<building[i])
				DP[i]=max(DP[i],DP[j]);
		DP[i]++;
		ans=max(ans,DP[i]);
	}
	printf("%d\n",ans);
	return 0;
}


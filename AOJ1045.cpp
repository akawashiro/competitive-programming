#include <stdio.h>
#include <algorithm>
#include <limits.h>

typedef long long LL;
using namespace std;

int main()
{
	while(1)
	{
		int n;
		LL sum=0,ans=1000000*20;
		int ar[25];
		scanf("%d",&n);
		if(n==0)
			break;
		for(int i=0;i<n;i++)
		{
			scanf("%d",ar+i);
			sum+=ar[i];
		}
		for(int mask=0;mask<1<<n;mask++)
		{
			LL a=0;
			for(int i=0;i<n;i++)
				if(mask & (1<<i))
					a+=ar[i];
			ans=min(ans,abs(sum-2*a));
		}
		printf("%lld\n",ans);
	}
	return 0;
}


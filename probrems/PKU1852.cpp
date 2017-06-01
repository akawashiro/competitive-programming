#include <cstdio>
#include <algorithm>
using namespace std;

void solve()
{
	int l,n;
	scanf("%d%d",&l,&n);
	int ans1=0,ans2=0;

	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		ans1=max(ans1,min(a,l-a));
		ans2=max(ans2,max(a,l-a));
	}

	printf("%d %d\n",ans1,ans2);
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		solve();
	return 0;
}


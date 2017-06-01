#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int n,m;
	int ans=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int a=0;
		for(int j=0;j<m;j++)
		{
			int b;
			scanf("%d",&b);
			a+=b;
		}
		ans=max(ans,a);
	}
	printf("%d\n",ans);
	return 0;
}


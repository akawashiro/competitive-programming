#include <algorithm>
#include <stdio.h>
#include <math.h>

using namespace std;

int pos[100000+10];

int main()
{
	int n,m,p=0,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n-1;i++)
	{
		int a;
		scanf("%d",&a);
		pos[i+1]=pos[i]+a;
	}
	for(int i=0;i<m;i++)
	{
		int d;
		scanf("%d",&d);
		ans+=abs(pos[p]-pos[p+d]);
		ans%=100000;
		p+=d;
	}
	printf("%d\n",ans);
	return 0;
}


#include <stdio.h>
#include <algorithm>
int a[1000];
int main()
{
	while(1){
		int n,m,ans=0;
		scanf("%d%d",&n,&m);
		if(!n)
			break;
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		std::sort(a,a+n);
		std::reverse(a,a+n);
		for(int i=0;i<n;i++)
			ans+=(i%m!=m-1)?a[i]:0;
		printf("%d\n",ans);
	}
	return 0;
}


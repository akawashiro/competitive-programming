#include <stdio.h>

int main()
{
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==0)
			break;
		int ans=0;
		for(int i=0;i<n;i+=4)
		{
			int a;
			scanf("%d",&a);
			ans+=a;
		}
		printf("%d\n",ans);
	}
	return 0;
}


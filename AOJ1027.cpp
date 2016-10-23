#include <stdio.h>

int main()
{
	while(1)
	{
		int K;
		scanf("%d",&K);
		if(K==0)
			break;
		int total=0;
		for(int i=0;i<K*(K-1)/2;i++)
		{
			int a;
			scanf("%d",&a);
			total+=a;
		}
		printf("%d\n",total/(K-1));
	}
	return 0;
}



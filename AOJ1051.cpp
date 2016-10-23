#include <stdio.h>

int main()
{
	while(1)
	{
		int n;
		int page[55];
		scanf("%d",&n);
		if(n==0)
			break;
		for(int i=0;i<n;i++)
			scanf("%d",page+i);
		int b=0,e=0,isF=1;
		while(1)
		{
			if(!isF)
				printf(" ");
			while(e<n-1 && (page[e]+1)==page[e+1])
				e++;

			if(b==e)
				printf("%d",page[b]);
			else
				printf("%d-%d",page[b],page[e]);
			if(e==n-1)
				break;
			b=e+1;
			e=b;
			if(isF)
				isF=0;
		}
		printf("\n");
	}
	return 0;
}


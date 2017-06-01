//AOJ0086
#include <stdio.h>
#include <string.h>
int ar[110];
int main()
{
	while(1){
		memset(ar,0,sizeof(ar));
		int a,b;
		if(scanf("%d%d",&a,&b)==EOF)
			break;
		ar[a]++,ar[b]++;
		while(1){
			scanf("%d%d",&a,&b);
				if(a==0 && b==0)
					break;
			ar[a]++,ar[b]++;
		}
		int ok=1;
		for(int i=3;i<110;i++)
			if(ar[i]%2==1)
				ok=0;
		if(ar[1]%2==0)
			ok=0;
		if(ok)
			printf("OK\n");
		else
			printf("NG\n");
	}
	return 0;
}


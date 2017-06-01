//AOJ0031
#include <stdio.h>
int main()
{
	while(1){
		int a;
		if(scanf("%d",&a)==EOF)
			break;
		int b=1;
		int f=1;
		for(int i=0;i<10;i++,b*=2)
			if(a&(1<<i)){
				if(!f)
					printf(" ");
				printf("%d",b);
				f=0;
			}
		printf("\n");
	}
	return 0;
}


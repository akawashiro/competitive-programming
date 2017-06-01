#include <stdio.h>

int main()
{
	while(1){
		int n;
		int sale[10];
		for(int i=0;i<10;i++)
			sale[i]=0;
		scanf("%d",&n);
		if(!n)
			break;
		for(int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			sale[a]++;
		}
		for(int i=0;i<10;i++){
			if(sale[i]==0)
				printf("-");
			else
				for(int j=0;j<sale[i];j++)
					printf("*");
			printf("\n");
		}
	}
	return 0;
}


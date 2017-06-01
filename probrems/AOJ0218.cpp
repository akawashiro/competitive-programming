#include <stdio.h>

int main()
{
	while(1){
		int n;
		scanf("%d",&n);
		if(!n)
			break;
		for(int i=0;i<n;i++){
			int m,e,j;
			scanf("%d%d%d",&m,&e,&j);
			if(m==100||e==100||j==100||180<=m+e||240<=m+e+j)
				printf("A\n");
			else if(210<=m+e+j||(150<=m+e+j&&(80<=m||80<=e)))
				printf("B\n");
			else
				printf("C\n");
		}
	}
	return 0;
}


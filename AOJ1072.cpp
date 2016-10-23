#include <stdio.h>

int main()
{
	while(1){
		int r,c;
		scanf("%d%d",&r,&c);
		if(r==0 && c==0)
			break;
		if(r*c%2==0)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}


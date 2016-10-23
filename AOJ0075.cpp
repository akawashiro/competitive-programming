//AOJ0075
#include <stdio.h>
int main()
{
	while(1){
		int n;
		double w,h;
		if(scanf("%d,%lf,%lf",&n,&w,&h)==EOF)
			break;
		if(25<=w/h/h)
			printf("%d\n",n);
	}
	return 0;
}


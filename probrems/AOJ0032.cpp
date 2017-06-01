//AOJ0032
#include <stdio.h>
int main()
{
	int ch=0,h=0;
	while(1){
		int a,b,c;
		if(scanf("%d,%d,%d",&a,&b,&c)==EOF)
			break;
		if(a*a+b*b==c*c)
			ch++;
		if(a==b)
			h++;
	}
	printf("%d\n%d\n",ch,h);
	return 0;
}


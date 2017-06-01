#include <stdio.h>

using namespace std;

int main()
{
	int sum=0,num=0,n=0,a,b;
	while(scanf("%d,%d",&a,&b)!=EOF)
		sum+=a*b,num+=b,n++;
	printf("%d\n%d\n",sum,(num/n+((5<=num%10)?1:0)));
	return 0;
}


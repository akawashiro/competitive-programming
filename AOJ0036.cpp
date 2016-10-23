//AOJ0136
#include <stdio.h>
int a[6];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		double d;
		scanf("%lf",&d);
		if(d<165)
			a[0]++;
		else if(d<170)
			a[1]++;
		else if(d<175)
			a[2]++;
		else if(d<180)
			a[3]++;
		else if(d<185)
			a[4]++;
		else
			a[5]++;
	}
	for(int i=0;i<6;i++){
		printf("%d:",i+1);
		for(int j=0;j<a[i];j++)
			printf("*");
		printf("\n");
	}
	return 0;
}


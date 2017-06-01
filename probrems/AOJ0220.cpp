#include <stdio.h>
double d[12]={128,64,32,16,8,4,2,1,0.5,0.25,0.125,0.0625};
int main()
{
	while(1){
		double n;
		scanf("%lf",&n);
		if(n<0)
			break;
		int a[12];
		for(int i=0;i<12;i++){
			a[i]=0;
			if(d[i]<=n){
				n-=d[i];
				a[i]=1;
			}
		}
		if(0<n)
			printf("NA\n");
		else{
			for(int i=0;i<8;i++)
				printf("%d",a[i]);
			printf(".");
			for(int i=8;i<12;i++)
				printf("%d",a[i]);
			printf("\n");
		}
	}
	return 0;
}


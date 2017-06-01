//AOJ1154
#include <stdio.h>
#define MAX_N 500000
int prime[MAX_N];
int C(int n){	return (n%7==1||n%7==6);	}
int main(){
	prime[0]=prime[1]=0;
	for(int i=2;i<MAX_N;i++){
		int b=0;
		if(C(i))
			b=1;
		for(int j=2;b&&j<i&&j*j<=i;j++)
			if(i%j==0&&C(j)&&C(i/j))
				b=0;
		if(b)
			prime[i]=1;
	}
	while(1){
		int n;
		scanf("%d",&n);
		if(n==1)	
			break;
		printf("%d:",n);
		for(int i=2;i<=n;i++)
			if(prime[i]&&n%i==0)
				printf(" %d",i);
		printf("\n");
	}
	return 0;
}


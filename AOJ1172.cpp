//AOJ1172
#include <stdio.h>
#define MAX_N 123456*2+1
int prime[MAX_N];
int num[MAX_N];
int main(){
	for(int i=0;i<MAX_N;i++)	prime[i]=1;
	prime[0]=prime[1]=0;
	for(int i=0;i<MAX_N;i++)
		if(prime[i])
			for(int j=i+i;j<MAX_N;j+=i)
				prime[j]=0;
	for(int i=1;i<MAX_N;i++)
		num[i]=num[i-1]+prime[i];
	while(1){
		int n;
		scanf("%d",&n);
		if(!n)
			break;
		printf("%d\n",num[n*2]-num[n]);
	}
	return 0;
}


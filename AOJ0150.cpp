//AOJ0150
#include <stdio.h>
int prime[10000+1];
int main(){
	for(int i=0;i<10000+1;i++)
		prime[i]=1;
	prime[0]=prime[1]=0;
	for(int i=0;i<10000+1;i++)
		if(prime[i])
			for(int j=i+i;j<10000+1;j+=i)
				prime[j]=0;
	while(1){
		int n;
		scanf("%d",&n);
		if(!n)
			break;
		int r;
		for(r=n;;r--)
			if(prime[r]&&prime[r-2])
				break;
		printf("%d %d\n",r-2,r);
	}
	return 0;
}


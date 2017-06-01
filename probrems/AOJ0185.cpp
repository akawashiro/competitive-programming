//AOJ0185
#include <stdio.h>
int prime[1000000+1];
int main(){
	for(int i=0;i<1000000+1;i++)
		prime[i]=1;
	prime[0]=prime[1]=0;
	for(int i=0;i<1000000+1;i++)
		if(prime[i])
			for(int j=i+i;j<1000000+1;j+=i)
				prime[j]=0;
	while(1){
		int n;
		scanf("%d",&n);
		if(!n)
			break;
		int ans=0;
		for(int i=0;i<=n/2;i++)
			if(prime[i]&&prime[n-i])
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}


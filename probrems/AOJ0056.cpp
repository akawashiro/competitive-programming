#include <stdio.h>
int prime[100000];
int main(){
	for(int i=0;i<100000;i++)
		prime[i]=1;
	prime[0]=prime[1]=0;
	for(int i=0;i<100000;i++)
		if(prime[i])
			for(int j=i+i;j<100000;j+=i)
				prime[j]=0;
	int n;
	while(1){
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


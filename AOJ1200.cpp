#include <stdio.h>
#define MAX_N (1<<16)
int prime[MAX_N];
int main(){
	for(int i=0;i<MAX_N;i++)	prime[i]=1;
	prime[0]=prime[1]=0;
	for(int i=0;i<MAX_N;i++)
		if(prime[i])
			for(int j=i+i;j<MAX_N;j+=i)
				prime[j]=0;
	while(1){
		int n,ans=0;
		scanf("%d",&n);
		if(!n)	break;
		for(int i=0;i+i<=n;i++)
			if(prime[i]&&prime[n-i])
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}


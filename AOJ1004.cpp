#include <stdio.h>
int prime[10000+1];
int main(){
	for(int i=0;i<=10000;i++)
		prime[i]=1;
	prime[0]=prime[1]=0;
	for(int i=0;i<=10000;i++)
		if(prime[i])
			for(int j=i+i;j<=10000;j+=i)
				prime[j]=0;
	int n;
	while(scanf("%d",&n)!=EOF){
		int ans=0;
		for(int i=1;i<=n;i++)
			if(prime[i]&&prime[n+1-i])
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}


//AOJ1141
#include <stdio.h>
int prime[1000001];
int main(){
	for(int i=0;i<1000001;i++)	prime[i]=1;
	prime[0]=prime[1]=0;
	for(int i=0;i<1000001;i++)
		if(prime[i])
			for(int j=i+i;j<1000001;j+=i)
				prime[j]=0;
	int a,d,n;
	while(1){
		scanf("%d%d%d",&a,&d,&n);
		if(!a&&!d&&!n)
			break;
		int i,c=0,ans;
		for(i=a;c<n;i+=d)
			if(prime[i])
				c++,ans=i;
		printf("%d\n",ans);
	}
	return 0;
}


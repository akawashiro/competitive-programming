//AOJ0162
#include <stdio.h>
int humming[5000000+1];
int sum[5000000+1];
int main(){
	humming[1]=1;
	for(int i=1;i<=1000000;i++)
		if(humming[i])
			humming[i*2]=humming[i*3]=humming[i*5]=1;
	for(int i=1;i<=1000000;i++)
		sum[i]=(humming[i])?sum[i-1]+1:sum[i-1];
	int n,m;
	while(1){
		scanf("%d",&n);
		if(!n)
			break;
		scanf("%d",&m);
		int ans=sum[m]-sum[n-1];
		printf("%d\n",ans);
	}
	return 0;
}


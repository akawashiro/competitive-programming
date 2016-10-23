//AOJ0202
#include <stdio.h>
int prime[1000000+1];
int pay[1000000+1];
int a[30];
int main()
{
	for(int i=0;i<1000000+1;i++)
		prime[i]=1;
	prime[0]=prime[1]=0;
	for(int i=0;i<1000000+1;i++)
		if(prime[i])
			for(int j=i+i;j<1000000+1;j+=i)
				prime[j]=0;
	prime[0]=prime[1]=1;
	while(1){
		int n,x;
		scanf("%d%d",&n,&x);
		if(!n&&!x)
			break;
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		for(int i=0;i<1000000+1;i++)
			pay[i]=0;
		pay[0]=1;
		for(int i=0;i<1000000+1;i++)
			if(pay[i])
				for(int j=0;j<n;j++)
					if(i+a[j]<1000000+1)
						pay[i+a[j]]=1;
		int ans;
		for(ans=x;0<=ans;ans--)
			if(pay[ans]&&prime[ans])
				break;
		if(ans==0)
			printf("NA\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}


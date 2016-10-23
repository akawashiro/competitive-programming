//AOJ0053
#include <stdio.h>
int p[1<<20];
int main()
{
	for(int i=0;i<(1<<20);i++)
		p[i]=1;
	p[0]=p[1]=0;
	for(int i=0;i<(1<<20);i++)
		if(p[i])
			for(int j=i*2;j<(1<<20);j+=i)
				p[j]=0;
	while(1){
		int n;
		long long s=0;
		scanf("%d",&n);
		if(!n)
			break;
		for(int i=0;0<n;i++)
			if(p[i]){
				n--;
				s+=i;
			}
		printf("%lld\n",s);
	}
	return 0;
}


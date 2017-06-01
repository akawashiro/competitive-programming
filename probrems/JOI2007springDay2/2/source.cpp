#include <stdio.h>

int powN[10000+10];
int numN[10000+10];

int main()
{
	int n,p;
	scanf("%d%d",&p,&n);
	for(int i=0;i<p;i++)
		numN[i]=0;
	for(int i=0;i<p;i++)
	{
		powN[i]=1;
		int t=i;
		for(int j=0;j<20;j++,t=(t*t)%p)
			if(n & (1<<j))
			{
				powN[i]*=t;
				powN[i]%=p;
			}
		numN[powN[i]]++;
	}
	int ans=0;
	for(int i=0;i<p;i++)
	{
		ans+=numN[powN[i]];
		ans+=numN[(powN[i]+1)%p]*(p-1);
	}
	/*for(int i=0;i<p;i++)
	{
		ans+=numN[(p-powN[i])%p];
		ans+=numN[(p-powN[i]-1)%p]*(p-1);
	}*/
	printf("%d\n",ans);
	return 0;
}


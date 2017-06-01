#include <stdio.h>
#include <string.h>

int n;
int dir[5010];
int f[5010];

int calc(int k)
{
	int r=0;
	int sum=0;
	memset(f,0,sizeof(f));
	for(int i=0;i+k-1<n;i++)
	{
		if((dir[i]+sum)%2==1)
			f[i]=1,r++,sum++;
		if(0<=i-k+1)
			sum-=f[i-k+1];
	}
	for(int i=n-k+1;i<n;i++)
	{
		if((dir[i]+sum)%2==1)
			return -1;
		if(0<=i-k+1)
			sum-=f[i-k+1];
	}
	return r;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		char c='\n';
		while(c=='\n')
			scanf("%c",&c);
		dir[i]=(c=='F')?0:1;
	}
	//for(int i=0;i<n;i++)
	//	printf("dir[%d]=%d\n",i,dir[i]);
	int K,M=n+1;
	for(int k=1;k<=n;k++)
	{
		int m=calc(k);
		if(m!=-1 && m<M)
			K=k,M=m;
	}
	printf("%d %d\n",K,M);
}



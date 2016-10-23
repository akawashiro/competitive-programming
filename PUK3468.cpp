#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long LL;

LL data[(1<<18)-1],datb[(1<<18)-1];

int N;

void add(int a,int b,int x,int k,int l,int r)
{
	//printf("add(%d,%d,%d,%d,%d,%d)\n",a,b,x,k,l,r);
	//fflush(stdout);
	if(b<=l || r<=a)
		return;
	else if(a<=l && r<=b)
	{
		data[k]+=x;
	}
	else
	{
		datb[k]+=(min(b,r)-max(a,l))*x;
		add(a,b,x,k*2+1,l,(l+r)/2);
		add(a,b,x,k*2+2,(l+r)/2,r);
	}
}

LL sum(int a,int b,int k,int l,int r)
{
	//printf("sum(%d,%d,%d,%d,%d)\n",a,b,k,l,r);
	//fflush(stdout);
	if(b<=l || r<=a)
	{
		return 0;
	}
	else if(a<=l && r<=b)
	{
		return data[k]*(r-l)+datb[k];
	}
	else
	{
		LL res=data[k]*((min(r,b)-max(l,a)));
		res+=sum(a,b,k*2+1,l,(l+r)/2);
		res+=sum(a,b,k*2+2,(l+r)/2,r);
		return res;
	}
}

int main()
{
	int Q;
	scanf("%d%d",&N,&Q);
	for(int i=0;i<N;i++)
	{
		int a;
		scanf("%d",&a);
		add(i,i+1,a,0,0,N);
		//printf("\n");
	}
	/*for(int i=0;i<32;i++)
		printf("%d ",data[i]);
	printf("\n");
	for(int i=0;i<32;i++)
		printf("%d ",datb[i]);
	printf("\n");*/
	for(int i=0;i<Q;i++)
	{
		char t='\n';
		int a,b,c;
		while(t=='\n')
			scanf("%c",&t);
		scanf("%d%d",&a,&b);
		if(t=='Q')
			printf("%lld\n",sum(a-1,b,0,0,N));
		else
		{
			scanf("%d",&c);
			add(a-1,b,c,0,0,N);
		}
		//printf("\n");
	}
	return 0;
}


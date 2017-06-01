#include <stdio.h>
#include <algorithm>

using namespace std;

int MOD=1234567;
int stair[1<<19];
int data[1<<20];
int datb[1<<20];

void add(int a,int b,int k,int l,int r,int x)
{
	if(a<=l && r<=b)
		data[k]=(data[k]+x)%MOD;
	else if(l<b && a<r)
	{
		datb[k]=(datb[k]+(min(r,b)-max(l,a))*x)%MOD;
		add(a,b,k*2+1,l,(l+r)/2,x);
		add(a,b,k*2+2,(l+r)/2,r,x);
	}
}

int sum(int a,int b,int k,int l,int r)
{
	if(r<=a || b<=l)
	   return 0;	
	else if(a<=l && r<=b)
		return (data[k]*(r-l)+datb[k])%MOD;
	else
	{
		int res=0;
		res+=(data[k]*(min(r,b)-max(l,a)))%MOD;
		res+=sum(a,b,k*2+1,l,(l+r)/2);
		res+=sum(a,b,k*2+2,(l+r)/2,r);
		return res%MOD;
	}
}

int main()
{
	int n,p;
	scanf("%d%d",&n,&p);
	n++;
	stair[0]=0;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		stair[i+1]=a+stair[i];
	}
	add(0,1,0,0,n,1);
	//printf("sum[0,1)=%d\n",sum(0,1,0,0,n));
	//printf("sum[0,2)=%d\n",sum(0,2,0,0,n));
	//printf("sum[1,2)=%d\n",sum(1,2,0,0,n));
	int ans=0;
	for(int i=1;i<n;i++)
	{
		int s=lower_bound(stair,stair+i,stair[i]-p)-stair;
		ans=sum(s,i,0,0,n);
		//printf/g("DP[%d]=%d\n",i,ans);
		add(i,i+1,0,0,n,ans);
	}
	printf("%d\n",ans);
	return 0;
}


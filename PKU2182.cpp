#include <cstdio>
#include <algorithm>

using namespace std;

int dat[1<<14];
int que[8000+10];
int ans[8000+10];

void init(int k,int l,int r)
{
	dat[k]=r-l;
	if(1<r-l)
	{
		init(k*2+1,l,(l+r)/2);
		init(k*2+2,(l+r)/2,r);
	}
}

int query(int x,int k,int l,int r)
{
	dat[k]--;
	if(r-l==1)
		return r;
	else if(x<=dat[k*2+1])
		return query(x,k*2+1,l,(l+r)/2);
	else
		return query(x-dat[k*2+1],k*2+2,(l+r)/2,r);
}

int main()
{
	int n;
	scanf("%d",&n);
	init(0,0,n);
	for(int i=0;i<n-1;i++)
		scanf("%d",que+i);
	for(int i=n-2;0<=i;i--)
		ans[i+1]=query(que[i]+1,0,0,n);
	ans[0]=query(1,0,0,n);
	for(int i=0;i<n;i++)
		printf("%d\n",ans[i]);
	return 0;
}


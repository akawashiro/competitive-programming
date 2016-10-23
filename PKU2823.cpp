#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int input[1000000];
int ans2[1000000];
int datmax[1<<22];
int datmin[1<<22];

void init(int k,int l,int r)
{
	if(r-l==1)
		datmax[k]=datmin[k]=input[l];
	else
	{
		init(k*2+1,l,(l+r)/2);
		init(k*2+2,(l+r)/2,r);
		datmax[k]=max(datmax[k*2+1],datmax[k*2+2]);
		datmin[k]=min(datmin[k*2+1],datmin[k*2+2]);
	}
}

int getMax(int a,int b,int k,int l,int r)
{
	if(b<=l || r<=a)
		return INT_MIN;
	else if(a<=l && r<=b)
		return datmax[k];
	else
		return max(getMax(a,b,k*2+1,l,(l+r)/2),getMax(a,b,k*2+2,(l+r)/2,r));
}

int getMin(int a,int b,int k,int l,int r)
{
	if(b<=l || r<=a)
		return INT_MAX;
	else if(a<=l && r<=b)
		return datmin[k];
	else
		return min(getMin(a,b,k*2+1,l,(l+r)/2),getMin(a,b,k*2+2,(l+r)/2,r));
}

int main()
{
	int n,w;
	scanf("%d%d",&n,&w);
	for(int i=0;i<1<<22;i++)
	{
		datmax[i]=INT_MIN;
		datmin[i]=INT_MAX;
	}
	for(int i=0;i<n;i++)
		scanf("%d",input+i);
	init(0,0,n);
	for(int i=0;i+w<=n;i++)
		printf("%d ",getMin(i,i+w,0,0,n));
	printf("\n");
	for(int i=0;i+w<=n;i++)
		printf("%d ",getMax(i,i+w,0,0,n));
	printf("\n");
	return 0;
}


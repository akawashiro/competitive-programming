#include <stdio.h>
#include <algorithm>

using namespace std;

int ar[100000+10];

void solve()
{
	int n,s;
	scanf("%d%d",&n,&s);
	for(int i=0;i<n;i++)
		scanf("%d",ar+i);
	int b=0,e=0,t=ar[0],r;
	while(t<s && e<n-1)
	{
		e++;
		t+=ar[e];
	}
	if(t<s)
	{
		printf("0\n");
		return;
	}
	while(s<=t-ar[b])
	{
		t-=ar[b];
		b++;
	}
	r=e-b+1;
	//printf("b=%d e=%d\n",b,e);
	e++;
	for(e;e<n;e++)
	{
		t+=ar[e];
		while(s<=t-ar[b])
		{
			t-=ar[b];
			b++;
		}
		//printf("b=%d e=%d\n",b,e);
		r=min(r,e-b+1);
	}
	printf("%d\n",r);
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
		solve();
	return 0;
}


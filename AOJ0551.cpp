#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int L,N;
int l[100000];
int cache[100000];

int rec(int k)
{
	if(cache[k]!=-1)
		return cache[k];
	else if(k==-1 || k==N)
		return 0;
	else
	{
		int t=0;
		if(l[k]<l[k-1])
			t=rec(k-1);
		if(l[k]<l[k+1])
			t=max(t,rec(k+1));
		return cache[k]=t+L-l[k];
	}
}

int main()
{
	scanf("%d%d",&N,&L);
	memset(cache,-1,sizeof(cache));
	for(int i=0;i<N;i++)
		scanf("%d",l+i);
	int ans=0;
	for(int i=0;i<N;i++)
		ans=max(ans,rec(i));
	printf("%d\n",ans);
}


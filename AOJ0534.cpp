#include <algorithm>
#include <stdio.h>

using namespace std;

int n;
int color[10000];

void solve()
{
	int ans=n;
	for(int start=0;start<n;start++)
		for(int c=1;c<4;c++)
		{
			int before=color[start];
			color[start]=c;
			int b=start;
			int e=start;
			int s=1;
			int r=n;
			while(1)
			{
				if(0<=b && e<n && color[b]!=color[e])
					break;
				while(0<b && color[b-1]==color[b])
					b--,s++;
				while(e<n-1 && color[e]==color[e+1])
					e++,s++;
				if(s<4)
					break;
				r-=s;
				b--,e++;
				s=2;
			}
			color[start]=before;
			ans=min(ans,r);
		}
	printf("%d\n",ans);
}

int main()
{
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		for(int i=0;i<n;i++)
			scanf("%d",color+i);
		solve();
	}
	return 0;
}


#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int used[100+10];
int chain[100+10][100+10];

int rec(int pos)
{
	int r=0;
	for(int i=0;i<100;i++)
		if(0<chain[pos][i] && used[i])
		{
			used[i]=0;
			chain[pos][i]--;
			chain[i][pos]--;
			r=max(r,rec(i)+1);
			chain[pos][i]++;
			chain[i][pos]++;
			used[i]=1;
		}
	return r;
}

int main()
{
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==0)
			break;
		memset(chain,0,sizeof(chain));
		memset(used,0,sizeof(used));
		for(int i=0;i<n;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			chain[a-1][b-1]++;
			chain[b-1][a-1]++;
			used[a-1]=used[b-1]=1;
		}
		int ans=0;
		fflush(stdout);
		for(int i=0;i<100;i++)
			if(used[i])
				ans=max(ans,rec(i));
		printf("%d\n",ans);
	}
	return 0;
}


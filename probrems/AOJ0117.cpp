#include <algorithm>
#include <cstdio>

using namespace std;

int dist[20][20];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			dist[i][j]=(i==j)?0:(1<<28);
	for(int i=0;i<m;i++)
	{
		int a,b,c,d;
		scanf("%d,%d,%d,%d",&a,&b,&c,&d);
		a--,b--;
		dist[a][b]=c;
		dist[b][a]=d;
	}
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

	int x1,x2,y1,y2;
	scanf("%d,%d,%d,%d",&x1,&x2,&y1,&y2);
	x1--,x2--;
	printf("%d\n",y1-y2-dist[x1][x2]-dist[x2][x1]);
	return 0;
}


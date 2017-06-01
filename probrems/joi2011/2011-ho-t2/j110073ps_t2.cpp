#include <vector>
#include <algorithm>
#include <functional>
#include <stdio.h>

using namespace std;

vector<vector<int> > book(10);
int cache[10][2000];

int rec(int g,int left)
{
	if(10<=g)
		return 0;
	if(cache[g][left]!=-1)
		return cache[g][left];

	int r=0;
	for(int num=0;num<=left;num++)
	{
		if(book[g].size()<num)
			continue;
		int a=0;
		for(int i=0;i<num;i++)
			a+=(book[g][i]+num-1);
		r=max(a+rec(g+1,left-num),r);
	}
	//printf("cache[%d][%d]=%d\n",g,left,r);
	return cache[g][left]=r;
}

int main()
{
	for(int i=0;i<10;i++)
		for(int j=0;j<2000;j++)
			cache[i][j]=-1;

	int N,K;
	scanf("%d %d",&N,&K);
	for(int i=0;i<N;i++)
	{
		int c,g;
		scanf("%d %d",&c,&g);
		g--;
		book[g].push_back(c);
	}
	for(int i=0;i<10;i++)
		sort(book[i].begin(),book[i].end(),greater<int>());

	int ans=rec(0,K);
	printf("%d\n",ans);
	return 0;
}


#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int n;
vector<int> G[100000+10];
vector<int> order;
int isAdded[100000+10];
int isAnounced[100000+10];

void tSort(int pos)
{
	if(isAdded[pos])
		return;
	isAdded[pos]=2;
	for(int i=0;i<G[pos].size();i++)
		tSort(G[pos][i]);
	isAdded[pos]=1;
	order.push_back(pos);
}

void anounce(int pos)
{
	if(isAnounced[pos])
		return;
	isAnounced[pos]=2;
	for(int i=0;i<G[pos].size();i++)
		anounce(G[pos][i]);
	isAnounced[pos]=1;
}

int main()
{
	int m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--,b--;
		G[a].push_back(b);
	}
	for(int i=0;i<n;i++)
		tSort(i);
	reverse(order.begin(),order.end());
	int ans=0;
	for(int i=0;i<n;i++)
		if(!isAnounced[order[i]])
		{
			anounce(order[i]);
			ans++;
		}
	printf("%d\n",ans);
	return 0;
}


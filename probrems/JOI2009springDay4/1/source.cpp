#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int value[10000+10];
vector<int> G[10000+10];

vector<int> rec(int k)
{
	vector<int> res;
	for(int i=0;i<(int)G[k].size();i++){
		vector<int> v=rec(G[k][i]);
		for(int i=0;i<v.size();i++)
			res.push_back(v[i]);
	}
	sort(res.begin(),res.end());
	if(res.size()==0)
		res.push_back(value[k]);
	else
		res[res.size()-1]+=value[k];
	return res;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int s,a;
		scanf("%d%d",&s,&a);
		G[s].push_back(i);
		value[i]=a;
	}
	vector<int> v=rec(0);
	reverse(v.begin(),v.end());
	int ans=0;
	for(int i=0;i<m && i<n;i++)
		ans+=v[i];
	printf("%d\n",ans);
	return 0;
}


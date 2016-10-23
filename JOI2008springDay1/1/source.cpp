#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int cache[100000+10];
int val[100000+10];
vector<int> sub[100000+10];

int rec(int pos)
{
	int &r=cache[pos];
	if(r!=-10000)
		return r;
	else
	{
		r=0;
		for(int i=0;i<sub[pos].size();i++)
			r=max(r,r+rec(sub[pos][i]));
		r+=val[pos];
		return r;
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int s,a;
		scanf("%d%d",&s,&a);
		val[i]=a;
		if(s!=0)
			sub[s-1].push_back(i);
		cache[i]=-10000;
	}
	int ans=-100;
	for(int i=0;i<n;i++)
		ans=max(ans,rec(i));
	printf("%d\n",ans);
	return 0;
}



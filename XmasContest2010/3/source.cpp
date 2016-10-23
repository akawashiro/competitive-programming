#include <vector>
#include <climits>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <iterator>
using namespace std;

class UNIONFIND
{
	vector<int> date;
	vector<int> scale;
	public:
	UNIONFIND(int n)
	{
		for(int i=0;i<n;i++)
		{
			date.push_back(i);
			scale.push_back(1);
		}
	}
	void unionSet(int x,int y)
	{
		scale[root(y)]+=scale[root(x)];
		scale[root(x)]=0;
		date[root(x)]=date[root(y)];
	}
	int unionSize(int n)
	{
		return scale[root(n)];
	}
	int root(int n)
	{
		if(date[n]==n)
			return n;
		else
			return date[n]=root(date[n]);
	}
};

int minAwkward(int n,vector<pair<int,pair<int,int> > > branch,vector<int> notNeed)
{
	int ans=INT_MAX;
	int nNsize=notNeed.size();

	for(int isExcept=0;isExcept<(1<<nNsize);isExcept++)
	{
		vector<int> isFavorite(n,true);
		vector<int> isNeed(n,true);

		for(int i=0;i<nNsize;i++)
		{
			isFavorite[notNeed[i]]=false;
			if(isExcept & (1<<i))
				isNeed[notNeed[i]]=false;
		}

		UNIONFIND u(n);
		int r=0;

		sort(branch.begin(),branch.end());
		for(int i=0;i<(int)branch.size();i++)
		{
			int a=branch[i].second.first,b=branch[i].second.second;

			if(isNeed[a] && isNeed[b] && u.root(a)!=u.root(b))
			{
				r+=branch[i].first;
				u.unionSet(a,b);
			}
		}

		int a=count(isNeed.begin(),isNeed.end(),true);
		for(int i=0;i<n;i++)
			if(a==u.unionSize(i))
			{
				ans=min(r,ans);
				break;
			}
	}

	return ans;
}

int main()
{
	while(1)
	{
		int N,M;
		scanf("%d %d",&N,&M);
		if(N==0 && M==0)
			break;

		vector<int> notNeed;
		for(int i=0;i<N;i++)
		{
			int a;
			scanf("%d",&a);
			if(a)
				notNeed.push_back(i);
		}
		vector<pair<int,pair<int,int> > > branch;
		for(int i=0;i<M;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			branch.push_back(make_pair(c,make_pair(a-1,b-1)));
		}
		printf("%d\n",minAwkward(N,branch,notNeed));
	}
	return 0;
}


#include <utility>
#include <set>
#include <vector>
#include <algorithm>
#include <string>

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
	int root(int n)
	{
		if(date[n]==n)
			return n;
		else
			return date[n]=root(date[n]);
	}
	void unionSet(int x,int y)
	{
		if(root(x)==root(y))
			return;
		scale[root(y)]+=scale[root(x)];
		scale[root(x)]=0;
		date[root(x)]=date[root(y)];
	}
	int unionSize(int n)
	{
		return scale[root(n)];
	}
};


class BestRoads
{
	public:
		vector <int> numberOfRoads(vector <string> input, int M)
		{
			int Rn=0,In=input.size();
			vector<pair<int,int> > road;
			for(int i=0;i<In;i++)
				for(int j=i+1;j<In;j++)
					if(input[i][j]=='Y')
						Rn++,road.push_back(make_pair(i,j));
			vector<bool> used(Rn,false);
			UNIONFIND U(In);
			vector<int> ans(In,0);
			int add=0;

			for(int i=0;i<Rn;i++)
				if(U.root(road[i].first)!=U.root(road[i].second))
				{
					U.unionSet(road[i].first,road[i].second);
					used[i]=true;
					ans[road[i].first]++;
					ans[road[i].second]++;
					add++;
				}
			int id=U.root(0);
			for(int i=0;i<In;i++)
				if(U.root(i)!=id)
					return vector<int>(0);
			if(add==M)
				return ans;
			for(int i=0;i<Rn;i++)
				if(!used[i])
				{
					ans[road[i].first]++;
					ans[road[i].second]++;
					add++;
					if(add==M)
						return ans;
				}
			return vector<int>(0);
		}
};


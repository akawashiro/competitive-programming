#include <vector>
#include <set>
#include <algorithm>
#include <stdio.h>

using namespace std;

class UNIONFIND
{
	vector<int> data;
	vector<int> scale;
	public:
	UNIONFIND(int n)
	{
		for(int i=0;i<n;i++)
		{
			data.push_back(i);
			scale.push_back(1);
		}
	}
	int root(int n)
	{
		if(data[n]==n)
			return n;
		else
			return data[n]=root(data[n]);
	}
	void set(int x,int y)
	{
		if(root(x)==root(y))
			return;
		scale[root(y)]+=scale[root(x)];
		scale[root(x)]=0;
		data[root(x)]=data[root(y)];
	}
	int size(int n)
	{
		return scale[root(n)];
	}
};

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	UNIONFIND u(n);
	set<int> se;
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--,b--;
		u.set(a,b);
	}
	for(int i=0;i<n;i++)
		se.insert(u.root(i));
	printf("%d\n",se.size()-1);
	return 0;
}


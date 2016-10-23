#include <algorithm>
#include <cstdio>
#include <vector>

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

void solve()
{
	int n,k,ans=0,type,a,b;
	scanf("%d%d",&n,&k);
	UNIONFIND u(3*n);

	for(int time=0;time<k;time++)
	{
		scanf("%d%d%d",&type,&a,&b);

		a--,b--;
		if(a<0 || n<=a || b<0 || n<=b)
		{
			ans++;
		}
		else if(type==1)
		{
			if(u.root(a)==u.root(b+n) || u.root(a)==u.root(b+2*n))
				ans++;
			else
			{
				u.set(a,b);
				u.set(a+n,b+n);
				u.set(a+2*n,b+2*n);
			}
		}
		else
		{
			if(u.root(a)==u.root(b) || u.root(a)==u.root(b+2*n))
				ans++;
			else
			{
				u.set(a,b+n);
				u.set(a+n,b+2*n);
				u.set(a+2*n,b);
			}
		}
	}
	printf("%d\n",ans);
	return;
}

int main()
{
	solve();
	return 0;
}


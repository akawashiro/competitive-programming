#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>

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
	while(1){
		int n,m;
		vector<pair<int,pair<int,int> > > road;
		scanf("%d",&n);
		if(n==0)
			break;
		scanf("%d",&m);
		UNIONFIND u(n);
		for(int i=0;i<m;i++){
			int a,b,c;
			scanf("%d,%d,%d",&a,&b,&c);
			road.push_back(make_pair(c/100-1,make_pair(a,b)));
			//printf("read a=%d b=%d c=%d\n",a,b,c);
		}
		int ans=0;
		sort(road.begin(),road.end());
		for(int i=0;i<m;i++){
			int a,b,c;
			a=road[i].second.first;
			b=road[i].second.second;
			c=road[i].first;
			//printf("set a=%d b=%d c=%d\n",a,b,c);
			if(u.root(a)!=u.root(b)){
				u.set(a,b);
				ans+=c;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}



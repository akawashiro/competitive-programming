#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>

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

typedef pair<int,pair<int,int> > P;

int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	UNIONFIND u(n);
	priority_queue<P,vector<P>,greater<P> > que;
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		que.push(make_pair(c,make_pair(a-1,b-1)));
	}
	int ans=0,t=n;
	while(t!=k){
		int a,b,c;
		c=que.top().first;
		a=que.top().second.first;
		b=que.top().second.second;
		que.pop();
		//printf("c=%d a=%d b=%d \n",c,a,b);
		if(u.root(a)==u.root(b))
			continue;
		u.set(a,b);
		ans+=c;
		t--;
	}
	printf("%d\n",ans);
	return 0;
}


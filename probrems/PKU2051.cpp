#include <queue>
#include <map>
#include <vector>
#include <functional>
#include <string>
#include <iostream>
#include <utility>

using namespace std;

typedef pair<int,int> P;

int main()
{
	map<int,int> ma;
	priority_queue<P,vector<P>,greater<P> > que;
	while(1)
	{
		int a,b;
		string s;
		cin>>s;
		if(s=="#")
			break;
		cin>>a>>b;
		ma[a]=b;
		que.push(make_pair(b,a));
	}
	int k;
	cin>>k;
	for(int i=0;i<k;i++)
	{
		int a,b;
		a=que.top().first;
		b=que.top().second;
		que.pop();
		cout<<b<<endl;
		que.push(make_pair(a+ma[b],b));
	}
	return 0;
}


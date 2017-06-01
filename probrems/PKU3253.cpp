#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
typedef long long LL;

void solve()
{
	int n;
	LL ans=0;
	cin >> n;
	priority_queue<LL,vector<LL>,greater<LL> > planks;
	for(int i=0;i<n;i++)
	{
		LL a;
		cin >> a;
		planks.push(a);
	}
	while(1<planks.size())
	{
		LL a,b;
		a=planks.top();
		planks.pop();
		b=planks.top();
		planks.pop();
		planks.push(a+b);
		ans+=a+b;
	}
	cout << ans << endl;
}

int main()
{
	solve();
	return 0;
}


#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <utility>
#include <algorithm>

using namespace std;

void solve(int n,int m,int a)
{
	vector<int> result(n+1);
	for(int i=0;i<n+1;i++)
		result[i]=i;
	vector<pair<int,pair<int,int> > > stick(m);
	for(int i=0;i<m;i++)
	{
		int h,p,q;
		cin >> h >> p >> q;
		stick[i].first=h;
		stick[i].second.first=p;
		stick[i].second.second=q;
	}
	sort(stick.begin(),stick.end());
	for(int i=0;i<m;i++)
		swap(result[stick[i].second.first],result[stick[i].second.second]);
	cout << result[a] << endl;
}

int main()
{
	int n,m,a;
	cin >> n >> m >> a;
	while(n!=0 || m!=0 || a!=0)
	{
		solve(n,m,a);
		cin >> n >> m >> a;
	}
	return 0;
}



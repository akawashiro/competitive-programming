#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;
typedef long long LL;

int n,m;

bool match(string s,string t)
{
	int i;
	for(i=0;i<8;i++)
		if(s[i]!='*' && s[i]!=t[i])
			break;
	return (i==8);
}

void solve()
{
	vector<pair<string,int> > hit;
	vector<string> ticket;

	for(int i=0;i<n;i++)
	{
		string s;
		int a;
		cin >> s >> a;
		hit.push_back(make_pair(s,a));
	}
	for(int i=0;i<m;i++)
	{
		string s;
		cin >> s;
		ticket.push_back(s);
	}

	int ans=0;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(match(hit[j].first,ticket[i]))
			{
				ans+=hit[j].second;
				break;
			}

	cout << ans << endl;
}

int main()
{
	while(1)
	{
		cin >> n >> m;
		if(n==0 && m==0)
			break;
		solve();
	}
	return 0;
}


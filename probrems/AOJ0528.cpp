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

string s,t;

void solve()
{
	int ans=0;
	vector<int> now(4000,0);

	for(int i=0;i<s.size();i++)
	{
		vector<int> pre=now;
		for(int j=0;j<t.size();j++)
		{
			if(i==0 || j==0)
				now[j]=(s[i]==t[j]) ? 1 : 0;
			else
				if(s[i]==t[j])
					now[j]=pre[j-1]+1;
				else
					now[j]=0;

			ans=max(ans,now[j]);
		}
	}

	cout << ans << endl;
}

int main()
{
	while(1)
	{
		if(!(cin >> s))
			break;
		if(!(cin >> t))
			break;

		solve();
	}
	return 0;
}


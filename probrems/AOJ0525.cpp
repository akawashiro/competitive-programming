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

int C,R;

void solve()
{
	vector<string> senbei(R,string(C,'#'));

	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
		{
			char c;
			cin >> c;
			senbei[i][j]=c;
		}

	int ans=0;

	for(int r=0;r<(1<<R);r++)
	{
		vector<string> s=senbei;
		for(int i=0;i<R;i++)
			if(r & (1<<i))
				for(int j=0;j<C;j++)
					s[i][j]=(s[i][j]=='1') ? '0' : '1';

		int sum=0;

		for(int j=0;j<C;j++)
		{
			int a=0;
			for(int i=0;i<R;i++)
				if(s[i][j]=='1')
					a++;
			sum+=max(a,R-a);
		}

		ans=max(sum,ans);
	}

	cout << ans << endl;
}

int main()
{
	while(1)
	{
		cin >> R >> C;
		if(R==0 && C==0)
			break;
		solve();
	}
	return 0;
}


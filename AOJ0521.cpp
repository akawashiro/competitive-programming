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

int n;

void solve()
{
	n=1000-n;
	int ans=0;
	ans+=n/500;
	n%=500;
	ans+=n/100;
	n%=100;
	ans+=n/50;
	n%=50;
	ans+=n/10;
	n%=10;
	ans+=n/5;
	n%=5;
	ans+=n/1;
	cout << ans << endl;
}

int main()
{
	while(1)
	{
		cin >> n;
		if(n==0)
			break;
		solve();
	}
	return 0;
}


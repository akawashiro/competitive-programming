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

double limitV;

void solve()
{
	int ans=1;
	while(1)
	{
		double t=sqrt((ans*5-5)/4.9);
		if(limitV<=t*9.8)
			break;
		ans++;
	}
	cout << ans << endl;
}

int main()
{
	while(cin >> limitV)
	{
		solve();
	}
	return 0;
}


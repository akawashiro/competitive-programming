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

int total;

void solve()
{
	for(int i=0;i<9;i++)
	{
		int a;
		cin >> a;
		total-=a;
	}

	cout << total << endl;
}

int main()
{
	while(1)
	{
		cin >> total;
		if(total==0)
			break;
		solve();
	}
	return 0;
}


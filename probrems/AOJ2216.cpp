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

int A,B;

void solve()
{
	int c=B-A;
	int t,f,h;
	
	t=c/1000;
	c%=1000;

	f=c/500;
	c%=500;

	h=c/100;

	cout << h << " " << f << " " << t << endl;
}

int main()
{
	while(1)
	{
		cin >> A >> B;
		if(A==0 && B==0)
			break;
		solve();
	}
	return 0;
}


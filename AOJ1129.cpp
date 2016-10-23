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

int n,r;

void solve()
{
	vector<int> card(n);
	for(int i=0;i<n;i++)
		card[i]=n-i;

	for(int time=0;time<r;time++)
	{
		vector<int> pre=card;
		int p,c;
		cin >> p >> c;

		for(int i=p-1,j=0;i<p-1+c;i++,j++)
			card[j]=pre[i];
		for(int i=0,j=c;i<p-1;i++,j++)
			card[j]=pre[i];
		for(int i=p+c;i<n;i++)
			card[i]=pre[i];
	}

	cout << card[0] << endl;
}

int main()
{
	while(1)
	{
		cin >> n >> r;
		if(n==0 && r==0)
			break;
		solve();
	}
	return 0;
}


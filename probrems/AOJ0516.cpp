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

int n,k;

void solve()
{
	vector<int> seq(n);
	for(int i=0;i<n;i++)
		cin >> seq[i];

	int sum=0;
	int ans=0;

	for(int i=0;i<k;i++)
		sum+=seq[i];
	ans=sum;

	for(int i=0;i+k<n;i++)
	{
		sum=sum-seq[i]+seq[i+k];
		ans=max(ans,sum);
	}

	cout << ans << endl;
}

int main()
{
	while(1)
	{
		cin >> n >> k;
		if(n==0 && k==0)
			break;
		solve();
	}
	return 0;
}

				

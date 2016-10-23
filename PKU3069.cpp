#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int R,n;

void solve()
{
	vector<int> troops(n);
	for(int i=0;i<n;i++)
		cin >> troops[i];
	sort(troops.begin(),troops.end());

	int ans=0,i=0,b=0;
	while(1)
	{
		ans++;
		for(i=b;i<n && troops[i]-troops[b]<=R;i++)
			;
		if(i==n)
			break;
		i--;
		b=i;
		for(i=b;i<n && troops[i]-troops[b]<=R;i++)
			;
		if(i==n)
			break;
		b=i;
	}
	cout << ans << endl;
}

int main()
{
	while(1)
	{
		cin >> R >> n;
		if(R==-1 && n==-1)
			break;
		solve();
	}
	return 0;
}


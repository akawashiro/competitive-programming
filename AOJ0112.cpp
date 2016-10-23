#include <iostream>
#include <vector>
#include <algorithm>

typedef long long LL;
using namespace std;

void solve(int n)
{
	LL r=0;
	vector<LL> v(n);
	for(int i=0;i<n;i++)
		cin >> v[i];

	sort(v.begin(),v.end());

	for(int i=1;i<n;i++)
	{
		r+=v[i-1];
		v[i]+=v[i-1];
	}

	cout << r << endl;
}

int main()
{
	int n;
	while(1)
	{
		cin >> n;
		if(n==0)
			break;
		solve(n);
	}
	return 0;
}


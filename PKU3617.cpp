#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

void solve()
{
	string s,r,ans;
	int b=0,e,n;

	cin >> n;
	e=n;
	for(int i=0;i<e;i++)
	{
		char c;
		cin >> c;
		s+=c;
	}
	r=s;
	reverse(r.begin(),r.end());

	while(b!=e)
	{
		if(s.substr(b)<r.substr(n-e))
		{
			ans+=s[b];
			b++;
		}
		else
		{
			ans+=r[n-e];
			e--;
		}
	}

	for(int i=0;i<n;i++)
	{
		if(i!=0 && i%80==0)
			cout << endl;
		cout << ans[i];
	}
}

int main()
{
	solve();
	return 0;
}


#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <utility>

using namespace std;

int string2int(string s)
{
	int r=0;
	for(int i=0;i<s.size();i++)
		if('0'<=s[i] && s[i]<='9')
		{
			r*=10;
			r+=s[i]-'0';
		}
	return r;
}

int n;
void solve()
{
	vector<pair<int,int> > timeTable;
	vector<bool> isUsed(n,false);

	for(int i=0;i<n;i++)
	{
		string s,t;
		cin >> s >> t;
		timeTable.push_back(make_pair(string2int(s),string2int(t)));
	}

	sort(timeTable.begin(),timeTable.end());

	int ans=0;
	while(count(isUsed.begin(),isUsed.end(),true)!=n)
	{
		ans++;
		int limit=0;
		for(int i=0;i<n;i++)
			if(!isUsed[i] && limit <= timeTable[i].first)
			{
				isUsed[i]=true;
				limit=timeTable[i].second;
			}
	}

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


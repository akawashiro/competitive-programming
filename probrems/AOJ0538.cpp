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

int n,m;

void solve()
{
	string source;
	cin >> source;

	vector<int> IOI;
	int i=0;
	while(i<m)
	{
		if(i+2<m && source[i]=='I' && source[i+1]=='O' && source[i+2]=='I')
		{
			int a=1;
			i+=3;
			while(i+1<m && source[i]=='O' && source[i+1]=='I')
			{
				a++;
				i+=2;
			}
			IOI.push_back(a);
		}
		else
			i++;
	}


	//for(int i=0;i<IOI.size();i++)
	//	cout << IOI[i] << " ";
	//cout << endl;

	int ans=0;
	for(int i=0;i<IOI.size();i++)
		ans+=max(0,IOI[i]-n+1);

	cout << ans << endl;
}

int main()
{
	while(1)
	{
		cin >> n;
		if(n==0)
			break;
		cin >> m;
		solve();
	}
	return 0;
}


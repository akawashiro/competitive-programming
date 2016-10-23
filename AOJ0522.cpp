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

string s;

void solve()
{
	int JOI=0,IOI=0;

	for(int i=0;i+2<s.size();i++)
	{
		if(s[i]=='J' && s[i+1]=='O' && s[i+2]=='I')
			JOI++;
		if(s[i]=='I' && s[i+1]=='O' && s[i+2]=='I')
			IOI++;
	}
	cout << JOI << endl << IOI << endl;
}

int main()
{
	while(cin >> s)
	{
		solve();
	}
	return 0;
}


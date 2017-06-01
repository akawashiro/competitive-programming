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

int main()
{
	string s;
	cin >> s;

	for(int i=0;i<s.size();i++)
	{
		if('D'<=s[i])
		{
			s[i]-=3;
			continue;
		}
		if(s[i]=='A')
			s[i]='X';
		if(s[i]=='B')
			s[i]='Y';
		if(s[i]=='C')
			s[i]='Z';
	}

	cout << s << endl;
	return 0;
}


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

int n,k;

vector<string> card;
vector<int> isUsed;
set<string> se;

void DFS(int k,string s)
{
	if(k==0)
		se.insert(s);
	else
		for(int i=0;i<(int)card.size();i++)
			if(!isUsed[i])
			{
				isUsed[i]=true;
				DFS(k-1,s+card[i]);
				isUsed[i]=false;
			}
}

void solve()
{
	card.clear();
	isUsed.clear();
	se.clear();

	for(int i=0;i<n;i++)
	{
		string s;
		cin >> s;
		card.push_back(s);
		isUsed.push_back(false);
	}

	DFS(k,"");

	cout << se.size() << endl;
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


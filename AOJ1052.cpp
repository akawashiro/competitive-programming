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

int n;

void solve()
{
	vector<pair<int,int> > bridge(n);
	for(int i=0;i<n;i++)
		cin >> bridge[i].second >> bridge[i].first;
	sort(bridge.begin(),bridge.end());
	//for(int i=0;i<n;i++)
	//	cout << bridge[i].second << " " << bridge[i].first << endl;

	int treasure=0;
	int i;
	for(i=0;i<n;i++)
	{
		treasure+=bridge[i].second;
		//cout << treasure << "---t" << endl;
		if(bridge[i].first < treasure)
			break;
	}

	if(i==n)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
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


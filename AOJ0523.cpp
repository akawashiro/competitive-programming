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

int n;

void solve()
{
	n*=2;

	vector<char> card(n,'H');
	int Tnum=n/2,Hnum=n/2,now=-1;

	for(int i=0;i<n/2;i++)
	{
		int a;
		cin >> a;
		a--;
		card[a]='T';
	}

	while(1)
	{
		int i;
		for(i=0;i<n;i++)
			if(card[i]=='T' && now<i)
			{
				card[i]='N';
				now=i;
				Tnum--;
				break;
			}
		if(i==n)
			now=-1;
		if(Tnum==0)
			break;


		for(i=0;i<n;i++)
			if(card[i]=='H' && now<i)
			{
				card[i]='N';
				now=i;
				Hnum--;
				break;
			}
		if(i==n)
			now=-1;
		if(Hnum==0)
			break;
	}

	cout << Hnum << endl << Tnum << endl;
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


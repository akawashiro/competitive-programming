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

int n,k;

void solve()
{
	int i;
	vector<int> card;
	bool isWild=false;

	for(i=0;i<k;i++)
	{
		int a;
		cin >> a;
		if(a==0)
			isWild=true;
		else
			card.push_back(a);
	}
	sort(card.begin(),card.end());

	vector<int> seq;
	i=0;
	while(i<(int)card.size())
	{
		int s=1,t=10;
		while(i+1<card.size() && card[i]+1==card[i+1])
		{
			s++;
			i++;
		}
		if(i+1<card.size() && card[i]+2==card[i+1])
			t=1;
		seq.push_back(s);
		seq.push_back(t);

		i++;
	}

	//
	/*for(i=0;i<seq.size();i++)
		cout << seq[i] << " ";
	cout << endl;*/
	//


	int ans=0;

	for(i=0;i<seq.size();i+=2)
		ans=max(ans,seq[i]);

	if(isWild)
	{
		ans+=1;
		for(i=1;i+1<seq.size();i+=2)
			if(seq[i]==1)
				ans=max(ans,seq[i-1]+1+seq[i+1]);
	}

	cout << ans << endl;
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

				

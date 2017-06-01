#include <map>
#include <queue>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

#define INF (1<<28)

using namespace std;

bool isSet(vector<pair<int,char> > cards)
{
	sort(cards.begin(),cards.end());
	if(cards[0].second == cards[1].second && cards[1].second == cards[2].second)
	{
		if(cards[0].first == cards[1].first && cards[1].first == cards[2].first)
			return true;
		if(cards[0].first+1 == cards[1].first && cards[0].first+2 == cards[2].first)
			return true;
	}
	return false;
}

void solve()
{
	vector<pair<int,char> > input(9);
	for(int i=0;i<9;i++)
		cin >> input[i].first;
	for(int i=0;i<9;i++)
		cin >> input[i].second;

	int order[8];
	for(int i=0;i<8;i++)
		order[i]=i;
	int ans=0;

	do{
		vector<pair<int,char> > v1,v2,v3;
		v1.push_back(input[order[0]]);
		v1.push_back(input[order[1]]);
		v1.push_back(input[order[2]]);

		v2.push_back(input[order[3]]);
		v2.push_back(input[order[4]]);
		v2.push_back(input[order[5]]);

		v3.push_back(input[order[6]]);
		v3.push_back(input[order[7]]);
		v3.push_back(input[8]);

		if(isSet(v1) && isSet(v2) && isSet(v3))
		{
			ans=1;
			break;
		}

	}while(next_permutation(order,order+8));

	cout << ans << endl;
}

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
		solve();
	return 0;
}


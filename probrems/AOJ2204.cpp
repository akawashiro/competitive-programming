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
	vector<int> score;
	for(int i=0;i<n;i++)
	{
		int a=0,b;
		for(int j=0;j<5;j++)
		{
			scanf("%d",&b);
			a+=b;
		}
		score.push_back(a);
	}

	sort(score.begin(),score.end());
	printf("%d %d\n",score.back(),score[0]);
}

int main()
{
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		solve();
	}
	return 0;
}


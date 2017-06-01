#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;
typedef long long LL;

int N,M;

void solve()
{
	int bydol[300][4];
	for(int i=0;i<N;i++)
	{
		char dmy[32];
		fgets(dmy,31,stdin); fgets(dmy,31,stdin);
		scanf("%d %d %d %d",&bydol[i][3],&bydol[i][0],&bydol[i][1],&bydol[i][2]);
	}

	int DP[300+1][3];
	for(int cost=0;cost<=M;cost++)
		for(int type=0;type<3;type++)
		{
			if(cost==0)
				DP[cost][type]=0;
			else
			{
				DP[cost][type]=DP[cost-1][type];
				for(int i=0;i<N;i++)
					if(0<=cost-bydol[i][3])
						DP[cost][type]=max(DP[cost][type],
								DP[cost-bydol[i][3]][type]+bydol[i][type]);
			}
		}

	int ans=0;
	for(int i=0;i<3;i++)
		ans=max(ans,DP[M][i]);

	printf("%d\n",ans);
}

int main()
{
	while(cin >> N)
	{
		scanf("%d",&M);
		solve();
	}
	return 0;
}


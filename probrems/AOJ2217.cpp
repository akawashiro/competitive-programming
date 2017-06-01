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

int N;

void solve()
{
	vector<int> floor(N*N);
	for(int i=0;i<N*N;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		floor[i]=y*N+x;
	}

	int ans=0;
	for(int start=0;start<N*N;start++)
	{
		int pos=start;
		bool isLoop=false;
		vector<bool> isVisited(N*N,false);

		while(1)
		{
			if(floor[pos]==-1)
				break;
			if(isVisited[pos])
			{
				isLoop=true;
				break;
			}
			isVisited[pos]=true;
			pos=floor[pos];
		}

		if(isLoop)
		{
			ans++;
			while(1)
			{
				if(floor[pos]==-1)
					break;
				int a=pos;
				pos=floor[pos];
				floor[a]=-1;
			}
		}
	}

	printf("%d\n",ans);
}

int main()
{
	while(1)
	{
		scanf("%d",&N);
		if(N==0)
			break;
		solve();
	}
	return 0;
}


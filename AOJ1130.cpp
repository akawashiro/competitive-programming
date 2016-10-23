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

int total;

int W,H;

void solve()
{
	vector<string> tile;
	for(int i=0;i<H;i++)
	{
		string s;
		cin >> s;
		tile.push_back(s);
	}

	queue<pair<int,int> > que;
	for(int i=0;i<H;i++)
		for(int j=0;j<W;j++)
		{
			if(tile[i][j]=='@')
			{
				que.push(make_pair(i,j));
				tile[i][j]='.';
			}
		}

	//printf("init\n");

	while(!que.empty())
	{
		int y=que.front().first;
		int x=que.front().second;
		que.pop();

		if(0<=y && y<H && 0<=x && x<W && tile[y][x]=='.')
		{
			tile[y][x]='B';
			que.push(make_pair(y+1,x));
			que.push(make_pair(y-1,x));
			que.push(make_pair(y,x+1));
			que.push(make_pair(y,x-1));
		}
	}

	//printf("BFS\n");

	int ans=0;
	for(int i=0;i<H;i++)
		for(int j=0;j<W;j++)
			if(tile[i][j]=='B')
				ans++;

	cout << ans << endl;
}

int main()
{
	while(1)
	{
		cin >> W >> H;
		if(H==0 && W==0)
			break;
		solve();
	}
	return 0;
}


#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int h,w;

void solve()
{
	vector<string> whiteMap,blackMap;
	for(int i=0;i<h;i++)
	{
		string s;
		cin >> s;
		whiteMap.push_back(s);
		blackMap.push_back(s);
	}

	queue<pair<int,int> > blackQueue,whiteQueue;
	for(int y=0;y<h;y++)
		for(int x=0;x<w;x++)
		{
			if(whiteMap[y][x]=='W')
			{
				whiteQueue.push(make_pair(y-1,x));
				whiteQueue.push(make_pair(y+1,x));
				whiteQueue.push(make_pair(y,x-1));
				whiteQueue.push(make_pair(y,x+1));
			}
			if(blackMap[y][x]=='B')
			{
				blackQueue.push(make_pair(y-1,x));
				blackQueue.push(make_pair(y+1,x));
				blackQueue.push(make_pair(y,x-1));
				blackQueue.push(make_pair(y,x+1));
			}
		}

	while(whiteQueue.size()!=0)
	{
		pair<int,int> q;
		q = whiteQueue.front();
		whiteQueue.pop();
		int y=q.first,x=q.second;

		if(!(0<=y && y<h && 0<=x && x<w) || whiteMap[y][x]!='.')
			continue;

		whiteMap[y][x]='w';
		whiteQueue.push(make_pair(y-1,x));
		whiteQueue.push(make_pair(y+1,x));
		whiteQueue.push(make_pair(y,x-1));
		whiteQueue.push(make_pair(y,x+1));
	}
	while(blackQueue.size()!=0)
	{
		pair<int,int> q;
		q = blackQueue.front();
		blackQueue.pop();
		int y=q.first,x=q.second;

		if(!(0<=y && y<h && 0<=x && x<w) || blackMap[y][x]!='.')
			continue;

		blackMap[y][x]='b';
		blackQueue.push(make_pair(y-1,x));
		blackQueue.push(make_pair(y+1,x));
		blackQueue.push(make_pair(y,x-1));
		blackQueue.push(make_pair(y,x+1));
	}

	int black=0,white=0;
	for(int y=0;y<h;y++)
		for(int x=0;x<w;x++)
		{
			if(blackMap[y][x]=='b' && whiteMap[y][x]=='.')
				black++;
			if(whiteMap[y][x]=='w' && blackMap[y][x]=='.')
				white++;
		}

	cout << black << " " << white << endl;
}

int main()
{
	while(1)
	{
		cin >> w >> h;
		if(h==0 && w==0)
			break;
		solve();
	}
	return 0;
}


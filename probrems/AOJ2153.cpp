#include <set>
#include <map>
#include <list>
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

class Q
{
	public:
		int y1,x1,y2,x2;
};

int W,H;

void solve()
{
	vector<string> room1;
	vector<string> room2;
	Q q;
	int yl,xl,yr,xr;
	int yg1,xg1,yg2,xg2;

	for(int i=0;i<H;i++)
	{
		string s;
		cin >> s;
		room1.push_back(s);
		for(int j=0;j<W;j++)
		{
			if(s[j]=='L')
				yl=i,xl=j;
			if(s[j]=='%')
				yg1=i,xg1=j;
		}

		cin >> s;
		room2.push_back(s);
		for(int j=0;j<W;j++)
		{
			if(s[j]=='R')
				yr=i,xr=j;
			if(s[j]=='%')
				yg2=i,xg2=j;
		}
	}

	queue<Q> que;
	bool isVisited[H][W][H][W];

	q.y1=yl,q.x1=xl,q.y2=yr,q.x2=xr;
	que.push(q);
	memset(isVisited,false,sizeof(isVisited));

	while(!que.empty())
	{
		q=que.front();
		que.pop();
		if(isVisited[q.y1][q.x1][q.y2][q.x2])
			continue;
		
		isVisited[q.y1][q.x1][q.y2][q.x2]=true;

		if(room1[q.y1][q.x1]=='%' || room2[q.y2][q.x2]=='%')
			continue;

		Q r;

		r.y1=q.y1,r.x1=q.x1,r.y2=q.y2,r.x2=q.x2;
		r.y1--,r.y2--;
		if(r.y1<0 || room1[r.y1][r.x1]=='#')	r.y1++;
		if(r.y2<0 || room2[r.y2][r.x2]=='#')	r.y2++;
		que.push(r);

		r.y1=q.y1,r.x1=q.x1,r.y2=q.y2,r.x2=q.x2;
		r.y1++,r.y2++;
		if(H<=r.y1 || room1[r.y1][r.x1]=='#')	r.y1--;
		if(H<=r.y2 || room2[r.y2][r.x2]=='#')	r.y2--;
		que.push(r);


		r.y1=q.y1,r.x1=q.x1,r.y2=q.y2,r.x2=q.x2;
		r.x1--,r.x2++;
		if(r.x1<0  || room1[r.y1][r.x1]=='#')	r.x1++;
		if(W<=r.x2 || room2[r.y2][r.x2]=='#')	r.x2--;
		que.push(r);

		r.y1=q.y1,r.x1=q.x1,r.y2=q.y2,r.x2=q.x2;
		r.x1++,r.x2--;
		if(W<=r.x1 || room1[r.y1][r.x1]=='#')	r.x1--;
		if(r.x2<0  ||  room2[r.y2][r.x2]=='#')	r.x2++;
		que.push(r);
	}

	if(isVisited[yg1][xg1][yg2][xg2])
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

int main()
{
	while(1)
	{
		cin >> W >> H;
		if(W==0 && H==0)
			break;
		solve();
	}
	return 0;
}

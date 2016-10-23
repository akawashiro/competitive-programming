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

int H,W,N;
int changeNum[1000][1000];
vector<string> town;

int rec(int y,int x)
{
	if(changeNum[y][x]!=-1)
		return changeNum[y][x];

	int r=0;
	if(0<y)
	{
		int a=rec(y-1,x);
		if(a%2==1 && town[y-1][x]=='0')
			r+=a/2+1;
		else
			r+=a/2;
	}
	if(0<x)
	{
		int a=rec(y,x-1);
		if(a%2==1 && town[y][x-1]=='1')
			r+=a/2+1;
		else
			r+=a/2;
	}
	return changeNum[y][x]=r;
}

void solve()
{
	memset(changeNum,-1,sizeof(changeNum));
	town.clear();

	for(int i=0;i<H;i++)
	{
		string s;
		for(int j=0;j<W;j++)
		{
			int c;
			cin >> c;
			s.push_back(c+'0');
		}
		town.push_back(s);
	}

	changeNum[0][0]=N-1;
	rec(H-1,W-1);
	
	for(int i=0;i<H;i++)
		for(int j=0;j<W;j++)
			if(changeNum[i][j]%2==1)
				town[i][j]=(town[i][j]=='1') ? '0' : '1';

	/*for(int i=0;i<H;i++)
		cout << town[i] << endl;
	cout << endl;*/

	int y=0,x=0;
	while(1)
	{
		if(town[y][x]=='0')
			y++;
		if(H<=y || W<=x)
			break;
		if(town[y][x]=='1')
			x++;
		if(H<=y || W<=x)
			break;
	}
	y++;
	x++;

	printf("%d %d\n",y,x);
}

int main()
{
	while(1)
	{
		cin >> H >> W >> N;
		if(H==0 && W==0 && N==0)
			break;
		solve();
	}
	return 0;
}


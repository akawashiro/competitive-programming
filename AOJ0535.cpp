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

int n,m;
vector<string> ice;

int DFS(int y,int x,int r)
{
	int rr=0;

	if(!(0<=y && y<n && 0<=x && x<m))
		return r;
	else if(ice[y][x]=='0')
		return r;
	else
	{
		ice[y][x]='0';
		rr=max(rr,DFS(y+1,x,r+1));
		rr=max(rr,DFS(y-1,x,r+1));
		rr=max(rr,DFS(y,x+1,r+1));
		rr=max(rr,DFS(y,x-1,r+1));
		ice[y][x]='1';

		return rr;
	}
}

void solve()
{
	ice.clear();
	for(int i=0;i<n;i++)
	{
		string s;
		for(int j=0;j<m;j++)
		{
			int c;
			cin >> c;
			c+='0';
			s+=c;
		}
		ice.push_back(s);
	}

	//for(int i=0;i<n;i++)
	//	cout << ice[i] << endl;

	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			ans=max(ans,DFS(i,j,0));

	printf("%d\n",ans);
}

int main()
{
	while(1)
	{
		scanf("%d%d",&m,&n);
		if(m==0 && n==0)
			break;

		solve();
	}
	return 0;
}


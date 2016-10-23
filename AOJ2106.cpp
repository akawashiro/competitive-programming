#include <map>
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

#define INF (1<<28)

using namespace std;

int L;
int Ea[100];
int cache[81][321][321];

int rec(int pos,int now,int pre)
{
	if(pos==L-1)
		return now;
	if(cache[pos][now][pre]!=-1)
		return cache[pos][now][pre];

	int r1=0,r2=0;
	if(0<now)
		r1=rec(pos+1,Ea[pos+1]+pre,now-1);
	r2=rec(pos+1,Ea[pos+1],now);

	return cache[pos][now][pre]=max(r1,r2);
}

void solve()
{
	memset(cache,-1,sizeof(cache));
	memset(Ea,-1,sizeof(Ea));

	cin >> L;
	for(int i=0;i<L;i++)
		cin >> Ea[i];

	int ans;
	if(L==1)
		ans=Ea[0];
	else
		ans=rec(1,Ea[1],Ea[0]);

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


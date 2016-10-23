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

int N,A,B,C,X;

void solve()
{
	vector<int> bingo;
	for(int i=0;i<N;i++)
	{
		int a;
		cin >> a;
		bingo.push_back(a);
	}

	int ans=0,pos=0;
	while(1)
	{
		if(bingo[pos]==X)
			pos++;
		if(pos==(int)bingo.size())
			break;

		X=(A*X+B)%C;
		ans++;
		if(ans==10001)
			break;
	}

	ans=(ans==10001) ? -1 : ans;
	cout << ans << endl;
}

int main()
{
	while(1)
	{
		cin >> N >> A >> B >> C >> X;
		if(N==0 && A==0 && B==0 && C==0 && X==0)
			break;
		solve();
	}
	return 0;
}


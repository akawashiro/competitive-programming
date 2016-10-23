#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

//int DP[2][(1<<20)];

void solve(int pNum)
{
	int T;
	cin >> T;
	vector<int> C(T);
	for(int i=0;i<T;i++)
		cin >> C[i];

	/*for(int pos=T-1;0<=pos;pos--)
		for(int bit=0;bit<(1<<20);bit++)
			if(pos==T-1)
				DP[pos%2][bit]=(bit==0)?C[pos]:-1;
			else
				DP[pos%2][bit]=max(DP[(pos+1)%2][bit^C[pos]]+C[pos],DP[(pos+1)%2][~(bit^C[pos])&((1<<20)-1)]);

	int r=DP[0][0];*/

	int r=0,m=(1<<28),s=0;
	for(int i=0;i<T;i++)
		r=r^C[i],m=min(m,C[i]),s+=C[i];

	if(r!=0)
		printf("Case #%d: NO\n",pNum);
	else
		printf("Case #%d: %d\n",pNum,s-m);

	return;
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		solve(i+1);
	return 0;
}


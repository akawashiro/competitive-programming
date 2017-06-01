#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M,P;

void solve()
{
	int sum=0;
	int hitNum=-1;

	for(int i=0;i<N;i++)
	{
		int x;
		cin >> x;
		if(i+1==M)
			hitNum=x;
		sum+=100*x;
	}
	if(hitNum==0)
		cout << "0" << endl;
	else
	{
		sum/=100;
		sum*=(100-P);
		cout << sum/hitNum << endl;;
	}
}

int main()
{
	while(1)
	{
		cin >> N >> M >> P;
		if(N==0 && M==0 && P==0)
			break;
		solve();
	}
	return 0;
}


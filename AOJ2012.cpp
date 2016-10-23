#include <cmath>
#include <iostream>
using namespace std;

int e;

bool isSqr(int n)
{
	int a=sqrt(n);
	return n==a*a;
}

void solve()
{
	int m=(1<<28),x,y,z;

	for(z=0;z*z*z<=e;z++)
	{
		int f=e-z*z*z;
		for(y=0;y*y<=f;y++)
		{
			x=f-y*y;
			m=min(x+y+z,m);
		}
	}

	cout << m << endl;
}

int main()
{
	while(1)
	{
		cin >> e;
		if(e==0)
			break;
		solve();
	}
	return 0;
}


#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

void solve(int h,int w,int s)
{
	int n;
	double r;
	r=sqrt(h*h+w*w);
	r=min(r,sqrt(h*h+s*s));
	r=min(r,sqrt(w*w+s*s));

	cin >> n;

	for(int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		a*=2;
		if(r<(double)a)
			cout << "OK" << endl;
		else
			cout << "NA" << endl;
	}
}

int main()
{
	int h,w,s;
	while(1)
	{
		cin >> h >> w >> s;
		if(h==0 && w==0 && s==0)
			break;
		solve(h,w,s);
	}
	return 0;
}


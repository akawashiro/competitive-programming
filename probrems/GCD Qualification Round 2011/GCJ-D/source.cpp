#include <algorithm>
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

void solve(int pNum)
{
	int n;
	cin >> n;
	vector<int> ar(n),cor;
	for(int i=0;i<n;i++)
		cin >> ar[i];
	cor=ar;
	sort(cor.begin(),cor.end());
	for(int i=0;i<n;i++)
		if(ar[i]==cor[i])
			ar[i]=-1;

	double ans=0.0;
	for(int i=0;i<n;i++)
		if(ar[i]!=-1)
		{
			int t=i;
			int d=0;
			while(ar[t]==-1)
			{
				int tt=ar[t];
				ar[t]=-1;
				t=tt;
				d++;
			}
			double r=1.0;
			for(int j=d;0<j;j--)
				r*=(double)j;
			ans+=r;
		}

	printf("Case #%d: %f\n",pNum,ans);
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



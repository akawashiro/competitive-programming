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

int a,b,c;

void solve()
{
	int n=a+b+c;
	vector<int> product(n,2);

	int N;
	cin >> N;
	vector<vector<int> > test(N,vector<int>(4));
	for(int i=0;i<N;i++)
	{
		cin >> test[i][0] >> test[i][1] >> test[i][2] >> test[i][3];
		test[i][0]--;
		test[i][1]--;
		test[i][2]--;
	}

	for(int i=0;i<N;i++)
		if(test[i][3]==1)
		{
			product[test[i][0]]=1;
			product[test[i][1]]=1;
			product[test[i][2]]=1;
		}

	for(int i=0;i<N;i++)
		if(test[i][3]==0)
		{
			if(product[test[i][0]]==1 && product[test[i][1]]==1)
				product[test[i][2]]=0;
			if(product[test[i][0]]==1 && product[test[i][2]]==1)
				product[test[i][1]]=0;
			if(product[test[i][1]]==1 && product[test[i][2]]==1)
				product[test[i][0]]=0;
		}

	for(int i=0;i<n;i++)
		cout << product[i] << endl;
}

int main()
{
	while(1)
	{
		cin >> a >> b >> c;
		if(a==0 && b==0 && c==0)
			break;
		solve();
	}
	return 0;
}


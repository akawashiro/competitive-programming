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

int N,P;
bool isPrime[1000000];

void solve()
{
	vector<int> prime;
	for(int i=N+1;prime.size()<P;i++)
		if(isPrime[i])
			prime.push_back(i);

	vector<int> comb;
	for(int i=0;i<prime.size();i++)
		for(int j=i;j<prime.size();j++)
			comb.push_back(prime[i]+prime[j]);
	sort(comb.begin(),comb.end());
	
	//for(int i=0;i<comb.size();i++)
	//	printf("comb[%d]=%d\n",i,comb[i]);

	cout << comb[P-1] << endl;
}

int main()
{
	for(int i=0;i<1000000;i++)
		isPrime[i]=true;
	isPrime[0]=false;
	isPrime[1]=false;

	for(int i=0;i<1000000;i++)
		if(isPrime[i])
			for(int j=i+i;j<1000000;j+=i)
				isPrime[j]=false;

	while(1)
	{
		cin >> N >> P;
		if(N==-1 && P==-1)
			break;
		solve();
	}
	return 0;
}


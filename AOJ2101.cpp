#include <algorithm>
#include <numeric>
#include <cmath>
#include <iostream>
#include <set>
using namespace std;

int solve(int n)
{
	set<int> se;
	for(int i=1;i<sqrt(n)+2;i++)
	{
		if(n%i==0)
		{
			se.insert(i);
			se.insert(n/i);
		}
	}
	return accumulate(se.begin(),se.end(),0)-n;
}

int main()
{
	int n;
	cin>>n;
	while(n!=0)
	{
		int r=solve(n);
		if(r<n)
			cout << "deficient number" << endl;
		if(r==n)
			cout << "perfect number" << endl;
		if(n<r)
			cout << "abundant number" << endl;
		cin>>n;
	}
	return 0;
}


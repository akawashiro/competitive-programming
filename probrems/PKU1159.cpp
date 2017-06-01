#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

string so,re;
short DP[5000+10][5000+10];

int main()
{
	int n;
	cin>>n;
	cin>>so;
	re=so;
	reverse(re.begin(),re.end());
	for(int s=0;s<=n;s++)
		for(int r=0;r<=n;r++)
		{
			if(s==0 || r==0)
				DP[s][r]=0;
			else if(so[s-1]==re[r-1])
				DP[s][r]=DP[s-1][r-1]+1;
			else
				DP[s][r]=max(DP[s-1][r],DP[s][r-1]);
		}
	cout<<n-DP[n][n]<<endl;
	return 0;
}


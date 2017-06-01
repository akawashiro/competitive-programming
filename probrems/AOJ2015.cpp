#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N,M;

vector<int> allSum(vector<int> v)
{
	int n=v.size();
	vector<vector<int> > dp(n,vector<int>(n,0));

	for(int len=0;len<n;len++)
		for(int i=0;i+len<n;i++)
		{
			if(len==0)
				dp[i][i+len]=v[i];
			else
				dp[i][i+len]=dp[i][i+len-1]+v[i+len];
		}

	vector<int> r;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(dp[i][j]!=0)
				r.push_back(dp[i][j]);

	return r;
}

void solve()
{
	vector<int> height,width,allHeight,allWidth;

	for(int i=0;i<N;i++)
	{
		int a;
		cin >> a;
		height.push_back(a);
	}
	allHeight=allSum(height);
	sort(allHeight.begin(),allHeight.end());

	for(int i=0;i<M;i++)
	{
		int a;
		cin >> a;
		width.push_back(a);
	}
	allWidth=allSum(width);
	sort(allWidth.begin(),allWidth.end());

	int ans=0;
	for(int i=0;i<(int)allHeight.size();i++)
		ans+=(int)distance(
				lower_bound(allWidth.begin(),allWidth.end(),allHeight[i]),
				upper_bound(allWidth.begin(),allWidth.end(),allHeight[i]));

	cout << ans << endl;
}

int main()
{
	while(1)
	{
		cin >> N >> M;
		if(N==0 && M==0)
			break;
		solve();
	}
	return 0;
}
	

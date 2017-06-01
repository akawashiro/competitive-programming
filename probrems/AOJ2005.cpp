#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(int n,int m,int s,int g1,int g2)
{
	s--;
	g1--;
	g2--;

	vector<vector<int> > base(n,vector<int>(n,(1<<28)));
	for(int i=0;i<m;i++)
	{
		int b1,b2,c;
		cin >> b1 >> b2 >> c;
		b1--;
		b2--;
		base[b1][b2]=c;
	}
	for(int i=0;i<n;i++)
		base[i][i]=0;

	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			base[i][j]=min(base[i][j],base[i][k]+base[k][j]);
	int ans=(1<<28);
	for(int i=0;i<n;i++)
		ans=min(ans,base[s][i]+base[i][g1]+base[i][g2]);
	cout << ans << endl;
}

int main()
{
	int n,m,s,g1,g2;
	cin >> n >> m >> s >> g1 >> g2;
	while(!(n==0 && m==0 && s==0 && g1==0 && g2==0))
	{
		solve(n,m,s,g1,g2);
		cin >> n >> m >> s >> g1 >> g2;
	}
	return 0;
}


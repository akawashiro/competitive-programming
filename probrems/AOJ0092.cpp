#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<string> square;
int DP[1000+10][1000+10];

int main()
{
	while(1)
	{
		int n,ans=0;
		cin>>n;
		if(n==0)
			break;
		square.clear();
		for(int i=0;i<n;i++)
		{
			string s;
			cin>>s;
			square.push_back(s);
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				if(i==0 || j==0)
					DP[i][j]=(square[i][j]=='.')?1:0;
				else
				{
					if(square[i][j]=='.')
						DP[i][j]=min(DP[i-1][j],min(DP[i][j-1],DP[i-1][j-1]))+1;
					else
						DP[i][j]=0;
				}
				ans=max(ans,DP[i][j]);
			}
		cout<<ans<<endl;
	}
	return 0;
}


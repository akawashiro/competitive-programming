#include <string>

using namespace std;

class MakeSquare
{
	public:

		string s,t;
		int n,m;
		int DP[50][50];

		int calc()
		{
			for(int i=n;0<=i;i--)
				for(int j=m;0<=j;j--)
				{
					if(i==n || j==m)
						DP[i][j]=n+m-i-j;
					else if(s[i]==t[j])
						DP[i][j]=DP[i+1][j+1];
					else
						DP[i][j]=min(DP[i+1][j],min(DP[i][j+1],DP[i+1][j+1]))+1;
				}
			return DP[0][0];
		}

		int minChanges(string S)
		{
			int ans=(1<<28);
			int Sn=S.size();
			for(int i=0;i<Sn;i++)
			{
				s=S.substr(0,i),t=S.substr(i,Sn-i);
				n=i,m=Sn-i;
				ans=min(ans,calc());
			}
			return ans;
		}
};


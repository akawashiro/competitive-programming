#include <string>

typedef long long LL;
using namespace std;

class TheDictionary
{
	public:

		LL C[110][110];
	
		string find(int n, int m, int _k)
		{
			LL k=_k;
			int len=n+m;
			string ans;
		
			for(int i=0;i<110;i++)
				for(int j=0;j<110;j++)
					if(i==0 || j==0)
						C[i][j]=1;
					else
						C[i][j]=min(k+1,C[i-1][j]+C[i][j-1]);

			for(int i=0;i<len;i++)
			{
				LL aN=(n!=0)?C[m][n-1]:0;
				LL zN=(m!=0)?C[n][m-1]:0;

				if(k<=aN)
					ans+='a',n--;
				else if(k<=aN+zN)
					ans+='z',k-=aN,m--;
				else
					return "";
			}

			return ans;
		}
};

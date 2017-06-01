#include <vector>
#include <string>
#include <climits>
using namespace std;

class NameImput{
	public:
		int countUpDownKeyPresses(vector <string> predictionSequence, vector <string> name)
		{
			string mojiretsu,uchitai;
			int dp[2600],next[2600];
			int n=mojiretsu.size();

			dp[0]=0;
			for(int i=1;i<n;i++)
				dp[i]=INT_MAX;

			for(int i=0;i<uchitai.size();i++)
			{
				for(int j=0;j<n;j++)
					next[i]=INT_MAX;

				int first,pl,dist;
				for(first=0;first<n;first++)
					if(mojiretsu[first]==uchitai[i])
						break;
				if(first==n)
					return -1;
				
				for(int j=0;j<n;j++)
				{
					if(mojiretsu[(first+j)%n]==uchitai[i])
						pl=(first+j)%n,dist=0;
					if(next[pl]>dp[(first+j)%n]+dist)
						next[pl]=dp[(first+j)%n]+dist;
					dist++;
				}
				for(int j=0;j<n;j++)
				{
					if(mojiretsu[(first+n-j)%n]==uchitai[i])
						pl=(first+n-j)%n,dist=0;
					if(next[pl]>dp[(first+n-j)%n]+dist)
						next[pl]=dp[(first+n-j)%n]+dist;
					dist++;
				}

				for(int j=0;j<n;j++)
					dp[j]=next[j];
			}

			int ans=INT_MAX;
			for(int i=0;i<n;i++)
				ans=min(ans,dp[i]);
			return res;
		}
};

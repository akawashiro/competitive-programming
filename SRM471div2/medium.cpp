#include <set>
#include <string>
#include <vector>
#define 100000007 MOD
using namespace std;

class EllysPlaylists{
	public:

		set<string> table;
		int n;
		int k;
		int dp[50][1001];

		int song2num(string song){
			return distance(table.begin(),table.find(song));
		}

		bool isCanConnect(string before,string after){
			if(before.substr(before.size()-3,3)==after.substr(0,3))
				return true;
			return false;
		}

		int countPlaylists(vector <string> songs, int kk)
		{
			n=songs.size();
			k=kk;
			for(int i=0;i<n;i++){
				table.insert(songs[i]);
				dp[i][0]=0;
				dp[i][1]=1;
			}
			for(int i=0;i<n;i++)
				for(int j=2;j<=k;j++)
					dp[i][j]=0;

			for(int i=2;i<=k;i++)
				for(int j=0;j<n;j++)
					for(int k=0;k<n;k++)
						if(isCanConnect(songs[j],songs[k])){
							dp[j][i]%=MOD;
							dp[j][i]+=(dp[k][i-1]%MOD);
							dp[j][i]%=MOD;
						}

			int ans=0;
			for(int i=0;i<n;i++){
				ans+=(dp[i][k]%MOD);
				ans%=MOD;
				}
			return ans;
		}
};

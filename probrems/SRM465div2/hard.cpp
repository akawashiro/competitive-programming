#include <vector>
#include <cstdio>
typedef long long LL;
using namespace std;

class WeirdTimes{
	public:
		vector <int> hourValues(vector <int> minuteValues, int K)
		{
			LL dp[50][24];
			int n=minuteValues.size();
			for(int i=0;i<n;i++){
				for(int j=0;j<24;j++){
					dp[i][j]=0;
					if(i==n-1)
						dp[i][j]=1;
				}
			}
			for(int i=n-2;0<=i;i--){
				for(int j=0;j<24;j++){
					for(int k=(minuteValues[i]<minuteValues[i+1]) ? j : j+1;k<24;k++){
						dp[i][j]+=dp[i+1][k];
					}
				}
			}
			}
			LL a=0;
			vector<int> ans;
			for(int i=0;i<24;i++){
				a+=dp[0][i];
			}
			if(a<K){
				ans.push_back(-1);
				return ans;
			}
			int j=0;
			for(int i=0;i<n;i++){
				for(j;j<24;j++){
					if(K<=dp[i][j]){
						ans.push_back(j);
						break;
					}
					K-=dp[i][j];
				}
				j=(minuteValues[i]<minuteValues[i+1]) ? j : j+1;
			}
			return ans;
		}
};

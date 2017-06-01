#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class ParkAmusement{
	public:
		double getProbability(vector <string> landings, int startLanding, int K)
		{
			double DP[50][50];
			int n=landings.size();
			
			for(int i=0;i<n;i++){
				DP[0][i]=0.0;
				if(find(landings[i].begin(),landings[i].end(),'E')!=landings[i].end())
					DP[0][i]=1.0;
			}

			for(int depth=1;depth<=K;depth++)
				for(int i=0;i<n;i++){
					DP[depth][i]=0.0;
					double ways=0;
					for(int j=0;j<n;j++)
						if(landings[i][j]=='1'){
							DP[depth][i]+=DP[depth-1][j];
							ways++;
						}
					DP[depth][i]=(ways==0) ? DP[depth][i] : DP[depth][i]/ways;
				}

			double all=0.0;
			for(int i=0;i<n;i++)
				all+=DP[K][i];
			return (all==0.0) ? 0.0 : DP[K][startLanding]/all;
		}
};

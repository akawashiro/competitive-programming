#include <string>
#include <vector>
using namespace std;

class SteeplechaseTrack{
	public:

		int maxComplexity(vector <string> fences, vector <string> tracks, int N)
		{
			int DP[100][50];
			int nFence=(int)fences.size();

			for(int i=0;i<nFence;i++)
				DP[0][i]=(fences[i][1]!='0') ? fences[i][1]-'0'+fences[i][0]-'0' : -1;

			for(int i=1;i<N;i++)
				for(int j=0;j<nFence;j++){
					DP[i][j]=-1;
					for(int k=0;k<nFence;k++)
						if(DP[i-1][k]!=-1 && tracks[k][j]!='0'){
							int a=DP[i-1][k]+tracks[k][j]-'0'+fences[j][0]-'0';
							DP[i][j]=max(a,DP[i][j]);
						}
				}

			int ans=-1;
			for(int i=0;i<N;i++)
				for(int j=0;j<nFence;j++)
					if(DP[i][j]!=-1 && fences[j][2]!='0')
						ans=max(ans,DP[i][j]+fences[j][2]-'0');

			return ans;
		}
};

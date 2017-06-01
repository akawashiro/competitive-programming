#include <string>
#include <vector>
using namespace std;

class StarAdventure{
	public:
		int w,h;
		int level[50][50];
		int dp[50][50][50][50];

		int mostStars(vector<string> level_input)
		{
			w=level_input[0].size();
			h=level_input.size();
			for(int i=0;i<h;i++)
				for(int j=0;j<w;j++)
					level[j][i]=level_input[j][i]-'0';

			if(h<=3 || w<=3){
				int ans=0;
				for(int i=0;i<h;i++)
					for(int j=0;j<w;j++)
						ans+=level[i][j];
				return ans;
			}

			for(int i=0;i<50;i++)
				for(int j=0;j<50;j++)
					for(int k=0;k<50;k++)
						for(int l=0;l<50;l++)
							dp[i][j][k][l]=0;
			for(int i=0;i<w;i++)
				for(int j=i+1;j<w;j++)
					for(int k=j+1;k<w;k++)
						dp[i][j][k][0]=level[i][h-1]+level[j][0]+level[k][0];

			for(int y=1;y<h;y++)
				for(int i=0;i<w;i++)
					for(int j=i+1;j<w;j++)
						for(int k=j+1;k<w;k++){
							int m=0;
							for(int i2=0;i2<=i;i2++)
								for(int j2=i2+1;j2<=j;j2++)
									for(int k2=j2+1;k2<=k;k++)
										m=max(m,dp[i2][j2][k2][y-1]);
							dp[i][j][k][y]=m;
						}

			int ans=0;
			for(int i=0;i<w;i++)
				for(int j=i+1;j<w;j++)
					for(int k=j+1;k<w;k++)
						ans=max(ans,dp[i][j][k][h-1]);
			return ans;
		}
};

#include <vector>
#include <algorithm>
#include <climits>

#define INF ((LL)1<<61)

typedef long long LL;

using namespace std;

class RabbitJumping
{
	public:
		int getMinimum(vector <int> holes, int _largeJump)
		{
			LL largeJump=_largeJump;
			
			if(largeJump%2==0)
				return -1;
		
			vector<LL> range;

			range.push_back(-INF);
			for(int i=0;i<holes.size();i++)
				range.push_back( (i%2==0) ? holes[i]-1 : holes[i]+1 );
			range.push_back(INF);

			int n=range.size()/2;
			int dist[n*2][n*2];

			for(int i=0;i<2*n;i++)
				for(int j=0;j<2*n;j++)
					dist[i][j]=INF;
			for(int i=0;i<n*2;i++)
				dist[i][i]=0;

			for(int i=0;i<n;i++)
				if(largeJump <= range[i*2+1]-range[i*2]+1)
					dist[i*2][i*2+1]=dist[i*2+1][i*2]=1;

			for(int i=0;i<n;i++)
				for(int j=i+1;j<n;j++)
				{
					if(range[j*2]-range[i*2+1] == largeJump)
					{
						int a=range[i*2+1]%2,b=range[j*2]%2;
						dist[i*2+a][j*2+b]=dist[j*2+b][i*2+a]=1;
					}
					else if(range[j*2+1]-range[i*2] == largeJump)
					{
						int a=range[i*2]%2,b=range[j*2+1]%2;
						dist[i*2+a][j*2+b]=dist[j*2+b][i*2+a]=1;
					}
					else if(largeJump < range[j*2+1]-range[i*2] && 
							range[j*2]-range[i*2+1] < largeJump)
					{
						dist[i*2][j*2+1]=dist[j*2+1][i*2]=1;
						dist[i*2+1][j*2]=dist[j*2][i*2+1]=1;
					}
				}

			bool isExist[n*2];
			for(int i=0;i<n;i++)
			{
				isExist[i*2]=isExist[i*2+1]=false;

				if(0 < range[i*2+1]-range[i*2])
					isExist[i*2]=isExist[i*2+1]=true;
				else if(range[i*2]==range[i*2+1] && range[i*2]%2==0)
					isExist[i*2]=true;
				else if(range[i*2]==range[i*2+1] && range[i*2]%2==1)
					isExist[i*2+1]=true;
			}

			for(int k=0;k<2*n;k++)
				for(int i=0;i<2*n;i++)
					for(int j=0;j<2*n;j++)
						if(isExist[i] && isExist[j])
							dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

			LL ans=dist[0][2*n-1];
			if(INF <= ans)
				ans=-1;

			return ans;
		}
};


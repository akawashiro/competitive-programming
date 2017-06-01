#include <string>
#include <vector>
#include <cstdio>

using namespace std;

class MatrixTransforming
{
	public:

		int minPushes(vector <string> start, vector <string> goal)
		{
			int h=start.size(),w=start[0].size();
			vector<vector<int> > diff(h,vector<int>(w,0));

			for(int i=0;i<h;i++)
				for(int j=0;j<w;j++)
					if(start[i][j]!=goal[i][j])
						diff[i][j]=1;

			int ans=0;
			for(int y=0;y<h-2;y++)
				for(int x=0;x<w-2;x++)
					if(diff[y][x]%2==1)
					{
						ans++;
						for(int i=y;i<y+3;i++)
							for(int j=x;j<x+3;j++)
								diff[i][j]++;
					}

			for(int i=0;i<h;i++)
				for(int j=0;j<w;j++)
					if(diff[i][j]%2==1)
						ans=-1;

			return ans;
		}
};


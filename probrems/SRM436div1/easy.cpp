#include <vector>
#include <stdio.h>
using namespace std;
typedef long long LL;

class BestView
{
	public:
		int numberOfBuildings(vector <int> heights)
		{
			int ans=0;
			bool isCanSee[50][50];
			memset(isCanSee,false,sizeof(isCanSee));

			for(int i=0;i<heights.size();i++)
				for(int j=i+1;j<heights.size();j++)
				{
					isCanSee[i][j]=true;
					isCanSee[j][i]=true;
					for(int k=i+1;k<j;k++)
					{
						LL a=(LL)heights[i]*(LL)(j-k)+(LL)heights[j]*(LL)(k-i);
						LL b=(LL)heights[k]*(LL)(j-i);
						if(a<=b)
						{
							isCanSee[i][j]=false;
							isCanSee[j][i]=false;
							break;
						}
					}
				}

			/*for(int i=0;i<heights.size();i++)
				{
				for(int j=0;j<heights.size();j++)
				printf("%d ",isCanSee[i][j]);
				printf("\n");
				}*/

			for(int i=0;i<heights.size();i++)
			{
				int a=0;
				for(int j=0;j<heights.size();j++)
					if(isCanSee[i][j])
						a++;
				ans=max(a,ans);
			}

			return ans;
		}
};

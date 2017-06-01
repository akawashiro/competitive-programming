#include <vector>
#include <iostream>
using namespace std;
typedef long long LL;

class TimeTravellingGardener
{
	public:

		int n;

		int minTree(vector<int> height,vector<int> distance,int a,int b)
		{
			//printf("%d %d",a,b);
			int r=0;
			for(int i=0;i<n;i++)
			{
				LL m=0,n=0;
				for(int j=min(a,i);j<max(a,i);j++)
					m+=distance[j];
				if(i<a)
					m*=(-1);
				for(int j=min(b,i);j<max(b,i);j++)
					n+=distance[j];
				if(b<i)
					n*=(-1);
				if((double)(height[a]*n+height[b]*m)/(double)(m+n)<(double)height[i])
				{
					r++;
				}
				if((double)(height[a]*n+height[b]*m)/(double)(m+n)>(double)height[i] ||  (double)(height[a]*n+height[b]*m)/(double)(m+n)<0)
				{
					r+=(1<<30);
					break;
				}
			}
			//printf("=%d\n",r);
			return ((1<<30)<=r) ? (1<<30) : r;
		}

		int determineUsage(vector <int> distance, vector <int> height)
		{
			int ans=(1<<30);
			n=height.size();

			for(int a=0;a<n;a++)
				for(int b=0;b<n;b++)
				{
					if(a==b)
						continue;
					ans=min(ans,minTree(height,distance,a,b));
					int c=height[a];
					height[a]=0;
					int d=minTree(height,distance,a,b);
					d++;
					ans=min(ans,d);
					height[a]=c;
					c=height[b];
					height[b]=0;
					d=minTree(height,distance,a,b);
					d++;
					ans=min(ans,d);
					height[b]=c;
					printf("\n");
				}
			return ans;
		}
};

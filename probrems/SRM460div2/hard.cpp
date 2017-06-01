//this is copy , too hahaha.
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class TheCitiesAndRoadsDivTwo{
	public:
		static const int N=9;

		int DFS(int n,int city[N],int i)
		{
			if(count(city,city+n,city[0])==n)
				return 1;
			int r=0;
			for(;i<n*n;i++)
			{
				int f=i%n;
				int t=i%n;
				if(f<t && city[f]!=city[t])
				{
					int c[N];
					for(int j=0;j<n;j++)
						c[j] = (city[j]==city[t]) ? city[f] : city[j];
					r+=DFS(n,c,i+1);
				}
			}
			return r;
		}

		int find(vector<string> map)
		{
			int n=map.size();
			int city[N];
			for(int i=0;i<n;i++)
				city[i]=i;
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					for(int k=0;k<n;k++)
						if(map[j][k]=='Y' && city[j]<city[k])
							city[k]=city[j];
			return DFS(n,city,0);
		}
		
};

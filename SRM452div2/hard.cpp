#include <vector>
#include <string>

using namespace std;

class HamiltonPath{
	public:

		bool isCircle(vector<string> roads,vector<int> isVisted,int s)
		{
			if(isVisted[s])
				return true;
			isVisted[s]=1;
			for(int i=0;i<roads.size();i++)
			{
				if(roads[s][i]=='Y')
				{
					roads[s][i]='N';	roads[i][s]='N';
					if(isCircle(roads,isVisted,i))
						return true;
					roads[s][i]='Y';	roads[i][s]='Y';
				}
			}
			return false;
		}

		bool checkBrench(vector<string> roads)
		{
			for(int i=0;i<roads.size();i++)
			{
				int b=0;
				for(int j=0;j<roads[i].size();j++)
					if(roads[i][j]=='Y')
						b++;
				if(3<=b)
					return true;
			}
			return false;
		}

		int countPaths(vector <string> roads)
		{
			int n=roads.size();
			for(int i=0;i<n;i++)
				if(isCircle(roads,vector<int>(n,0),i))
					return 0;
			if(checkBrench(roads))
				return 0;
			
			vector<int> group(n);
			for(int i=0;i<n;i++)
				group[i]=i;
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
				{
					if(roads[i][j]=='Y')
					{
						group[i]=min(group[i],group[j]);
						group[j]=min(group[i],group[j]);
					}
				}
				
			int gMax=0;
			for(int i=0;i<n;i++)
				gMax=max(gMax,group[i]);
			vector<int> seibun(gMax+1,0);
			for(int i=0;i<n;i++)
				seibun[group[i]]++;

			long long ans=1;
			long long l=1;
			for(int i=0;i<seibun.size();i++){
				if(0<seibun[i])
				{
					ans*=l;
					ans%=1000000007;
					ans*=(1<seibun[i]) ? 2 : 1;
					ans%=1000000007;
					l++;
				}
			}
			return ans;
		}
};

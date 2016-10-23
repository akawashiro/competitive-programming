#include <algorithm>
#include <vector>

using namespace std;

class MostLikely
{
	public:
		int likelyRank(vector <int> sc, int low, int high)
		{
			vector<int> rank(55,0);
			sc.push_back(1000000000+1);
			sc.push_back(-1);
			sort(sc.begin(),sc.end());
			reverse(sc.begin(),sc.end());

			for(int i=1;i<(int)sc.size();i++)
				if(sc[i-1]==sc[i])
					;
				else if(sc[i]<low && high<sc[i-1])
					rank[i]=high-low+1;
				else if(sc[i]<low)
					rank[i]=sc[i-1]-low;
				else if(high<sc[i-1])
					rank[i]=high-sc[i]+1;
				else
					rank[i]=sc[i-1]-sc[i];
					
			int m=*max_element(rank.begin(),rank.end());
			if(1<(int)count(rank.begin(),rank.end(),m))
				return -1;
			for(int i=0;i<55;i++)
				if(rank[i]==m)
					return i;
			return -2;
		}
};


#include <algorithm>
#include <vector>

using namespace std;

class MafiaGame
{
	public:
		double probabilityToLose(int N, vector<int> decisions)
		{
			vector<int> v(N,0);
			for(int i=0;i<(int)decisions.size();i++)
				v[decisions[i]]++;
			sort(v.begin(),v.end());
			reverse(v.begin(),v.end());
			int most=v[0],Nmost=0;
			for(int i=0;i<N;i++)
				if(v[i]==most)
					Nmost++;
			if(most==1)
				return 0.0;
			if(Nmost==1)
				return 1.0;
				
			int preMost=Nmost;
			while(1)
			{
				int m=preMost;
				int left=N-m*most;
				if(left%m==0)
					return 0.0;
				else if(left%m==1)
					return 1.0/(double)Nmost;
				else
					m=left%m;
				preMost=m;
			}
		}
};

// This is copy of ACRush
#include <algorithm>
#include <vector>
#include <utility>
#include <climits>
typedef long long LL;
using namespace std;

class UnluckyIntervals
{
	public:
		vector<int> getLuckList(vector<int> A,int n)
		{
			A.push_back(0);
			vactor<int> candiate;
			for(int i=1;i<=n;i++)
				candiate.push_back(i);
			sort(A.begin(),A.end());
			for(int i=0;i<A.size();i++)
				for(int d=-n;d<=n;d++)
					if(0<d+A[i])
						candiate.push_back(A[i]+d);
			sort(candiate.begin(),candiate.end());
			candiate.resize(unique(candiate.begin(),candiate.end())-candiate.begin());
			vector<pair<LL,int> > result;
			for(int i=0;i<candiate.size();i++)
			{
				int key=candiate[i];
				LL R;
				if(key<A[0] || A[A.size()-1]<key)
					R=LLONG_MAX;
				else
					for(int i=0;i<A.size();i++)
					{
						if(key==A[i])
						{
							R=0;
							break;
						}else if(i+1<A.size() && A[i]<key && key<A[i+1]){
							R=(LL)(key-A[i])*(LL)(A[i+1]-key)-1;
							break;
						}
					}
				result.push_back(make_pair(R,key));
			}
			sort(result.begin(),result.end());
			vector<int> ret;
			for(int i=0;i<n;i++)
				ret.push_back(result[i].second);
			return ret;
		}
};


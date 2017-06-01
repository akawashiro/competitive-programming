#include <map>

typedef long long LL;
using namespace std;

class InfiniteSequence
{
	public:
		map<LL,LL> seq;
		LL p,q;
		
		LL rec(LL index)
		{
			if(seq.find(index)!=seq.end())
				return seq[index];
			else
				return seq[index]=rec(index/p)+rec(index/q);
		}
		
		LL calc(LL n, int _p, int _q)
		{
			p=_p,q=_q;
			seq[0]=1;
			
			return rec(n);
		}
};

				

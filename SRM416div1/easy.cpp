#include <algorithm>
using namespace std;

class NextNumber
{
	public:
		int getNextNumber(int N)
		{
			int s[32];
			for(int i=0;i<32;i++)
				s[31-i]=(0<(N&(1<<i)));
			next_permutation(s,s+32);
			N=0;
			for(int i=0;i<32;i++)
				N+=(s[i]<<(31-i));
			return N;
		}
};

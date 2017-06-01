//this is copy

#include <algorithm>

using namespace std;

class KidsGame
{
	public:
		int kthKid(int n, int m, int k)
		{
			int curIndex = (m-1+n)%n+1;
			int beforeK = k-1;
			int nr = 1;

			while(curIndex!=beforeK+1)
			{
				if(curIndex < beforeK+1)
					beforeK--;
				nr++;
				n--;
				curIndex = (curIndex-1+m+n-1)%n+1;
			}

			return nr;
		}
};


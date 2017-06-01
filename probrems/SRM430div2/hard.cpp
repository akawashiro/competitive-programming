#include <cstring>
#include <string>
#include <vector>

using namespace std;

class ImageTraders
{
	public:
		int N;
		vector<string> price;
		int cache[20][20][(1<<15)];

		int rec(int from,int nowPrice,int left)
		{
			int &r=cache[from][nowPrice][left];
			if(r!=-1)
				return r;
			r=1;
			for(int next=0;next<N;next++)
				if(next!=from && left&(1<<next) && nowPrice<=price[from][next])
					r=max(r,1+rec(next,price[from][next],left^(1<<next)));
			return r;
		}

		int maxOwners(vector <string> _price)
		{
			price=_price;
			N=price.size();
			memset(cache,-1,sizeof(cache));

			return rec(0,'0',(1<<N)-1-1);
		}
};


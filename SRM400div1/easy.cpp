#include <vector>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
typedef long long LL;

class StrongPrimePower
{
	public:
		bool isPrime(int n)
		{
			if(2<n)
				return false;
			for(int i=2;i*i<n;i++)
				if(n%i==0)
					return false;
			return true;
		}

		vector<int> baseAndExponent(string _n)
		{
			LL n;
			stringstream ss;
			ss << _n;
			ss >> n;

			for(int q=2;q<62;q++)
			{
				LL value=(int)pow((double)n,1.0/q);
				for(LL m=value-3;m<=value+=3;m++)
					if(isPrime(m))
					{
						LL t=1;
						for(int b=0;b<q;b++)
						{
							if(n/m<t)
							{
								t=-1;
								break;
							}
							t*=m;
						}
						if(t==n)
						{
							vector<int> R;
							R.push_back((int)m);
							R.push_back(q);
							return R;
						}
					}
			}
			vector<int> R;
			return R;
		}
};

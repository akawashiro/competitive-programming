#include <vector>
#include <algorithm>
#include <functional>

typedef long long LL;

using namespace std;

class SignalIntelligence
{
	public:

		LL encrypt(vector <int> numbers)
		{
			int n=numbers.size();
			sort(numbers.begin(),numbers.end());

			LL ans=((LL)1<<62);

			for(int last=0;last<n;last++)
			{
				LL s=1,e=1;
				for(int i=0;i<n;i++)
					if(i!=last)
					{
						while(e-s-1 < (LL)numbers[i])
							e*=2;
						s=e;
						if( ((LL)1<<62) <= e)
							goto failed;
					}
				ans=min(ans,s+numbers[last]-1);
				failed:;
			}
			return ans;
		}
};


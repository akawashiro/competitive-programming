#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Inequalities{
	public:
		int maximumSubset(vector <string> ineq)
		{
			int num[3002];
			int offset=1;
			for(int i=-1;i<=3000;i++)
				num[i+offset]=0;
			for(int i=0;i<ineq.size();i++){
				stringstream ss(ineq[i]);
				char X;
				int C;
				string sign;
				ss >> X >> sign >> C;
				C*=2;
				if(sign=="<")
					for(int i=-1;i<C;i++)
						num[i+offset]++;
				else if(sign=="<=")
					for(int i=-1;i<=C;i++)
						num[i+offset]++;
				else if(sign=="=")
					num[C+offset]++;
				else if(sign==">")
					for(int i=C+1;i<=3000;i++)
						num[i+offset]++;
				else if(sign==">=")
					for(int i=C;i<=3000;i++)
						num[i+offset]++;
				//printf("num[%d]=%d\n",521*2+offset,num[521*2+offset]);
			}
			int ans=0;
			for(int i=-1;i<=3000;i++)
				ans=max(ans,num[i+offset]);
			return ans;
		}
};

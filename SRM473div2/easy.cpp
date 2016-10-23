#include <vector>
using namespace std;

class OnTheFarmDivTwo{
	public:
		vector <int> animals(int heads, int legs)
		{
			vector<int> ans;
			if(heads==0 && legs==0){
				ans.push_back(0);
				ans.push_back(0);
				return ans;
			}
			if(heads==0 || legs==0 || legs%2==1){
				return ans;
			}
			int x,y;
			y=legs/2-heads;
			x=heads-y;
			if(x<0 || y<0){
				return ans;
			}
			ans.push_back(x);
			ans.push_back(y);
			return ans;
		}
};

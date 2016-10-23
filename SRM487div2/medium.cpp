#include <vector>
using namespace std;

class BunnyComputer{
	public:
		int subMax(vector<int> sub,int after)
		{
			if(after+1==sub.size())
				return sub[after];
			if(after+2==sub.size())
				return max(sub[after],sub[after+1]);
			return max(sub[after]+subMax(sub,after+2),subMax(sub,after+1));
		}

		int getMaximum(vector <int> preference, int k)
		{
			int ans=0;
			for(int i=0;i<k+1;i++){
				vector<int> sub;
				if(preference.size()<=i+k+1)
					continue;
				for(int j=i+k+1;j<preference.size();j+=k+1)
					sub.push_back(preference[j]+preference[j-k-1]);
				ans+=subMax(sub,0);
			}
			return ans;
		}
};

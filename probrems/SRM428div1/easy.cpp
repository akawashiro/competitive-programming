#include <string>
#include <algorithm>
using namespace std;

class TheLuckyString
{
	public:
		int count(string s)
		{
			int ans=0;
			sort(s.begin(),s.end());
			do{
				ans++;
				for(int i=0;i<s.size()-1;i++)
					if(s[i]==s[i+1])
					{
						ans--;
						break;
					}
			}while(next_permutation(s.begin(),s.end()));
			return ans;
		}
};

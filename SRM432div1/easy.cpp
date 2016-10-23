#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class LampsGrid
{
	public:

		int count_on(string s)
		{
			int r=0;
			for(int i=0;i<s.size();i++)
				if(s[i]=='1')
					r++;
			return r;
		}

		int mostLit(vector <string> initial, int K)
		{
			int ans=0,h=initial.size(),w=initial[0].size();

			for(int i=0;i<h;i++)
			{
				vector<string> l=initial;
				if(w-count_on(l[i])<=K && (w-count_on(l[i]))%2==K%2)
				{
					int a=0;
					string s=l[i];
					for(int j=0;j<h;j++)
					{
						for(int k=0;k<w;k++)
							if(s[k]=='0')
								l[j][k]=(l[j][k]==0) ? '1' : '0';
						if(count_on(l[j])==w)
							a++;
					}
					ans=max(a,ans);
				}
			}
			return ans;
		}
};

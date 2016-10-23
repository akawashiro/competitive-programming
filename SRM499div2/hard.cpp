#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class PalindromeGame
{
	public:
		int getMaximum(vector <string> front, vector <int> back)
		{
			int n=front.size(),ans=0;
			vector<int> used(n,false);
			for(int i=0;i<n;i++)
				for(int j=0;j<n-1;j++)
					if(back[j]<back[j+1])
						swap(front[j],front[j+1]),swap(back[j],back[j+1]);

			for(int i=0;i<n;i++)
				for(int j=i+1;j<n;j++)
					if(!used[i] && !used[j])
					{
						string s=front[i];
						reverse(s.begin(),s.end());
						if(s==front[j])
							used[i]=used[j]=true,ans+=back[i]+back[j];
					}
			for(int i=0;i<n;i++)
				if(!used[i])
				{
					string s=front[i];
					reverse(s.begin(),s.end());
					if(s==front[i])
					{
						used[i]=true,ans+=back[i];
						break;
					}
				}

			return ans;
		}
};


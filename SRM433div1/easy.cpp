#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class MagicWords
{
	public:

		bool isCycle(string s,int K)
		{
			string t=s;
			for(int i=0;i<s.size();i++)
			{
				rotate(s.begin(),s.begin()+1,s.end());
				if(s==t)
					K--;
			}
			return (K==0);
		}

		int count(vector <string> S, int K)
		{
			int ans=0,n=S.size();
			vector<int> order;
			for(int i=0;i<n;i++)
				order.push_back(i);

			do{
				string s;
				for(int i=0;i<n;i++)
					s+=S[order[i]];

				if(isCycle(s,K))
					ans++;
			}while(next_permutation(order.begin()+1,order.end()));

			return ans*n;
		}
};

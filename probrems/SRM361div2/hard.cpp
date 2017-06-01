#include <algorithm>
#include <functional>
#include <utility>
#include <vector>

typedef long long LL;
using namespace std;

class CAND
{
	public:
	int id,votes;
	bool operator>(const CAND &c)
	const{
		LL a=(LL)votes*100-id;
		LL b=(LL)c.votes*100-c.id;
		return a>b;
	}
};

class Election
{
	public:
		int votesNeeded(vector <int> votes, vector <int> wishList)
		{
			int n=votes.size();

			vector<CAND> v;
			vector<CAND> candiates(n);
			for(int i=0;i<n;i++)
			{
				CAND c;
				c.id=-1,c.votes=-1;
				candiates[i]=c;
			}

			for(int i=0;i<n;i++)
			{
				CAND c;
				c.id=i,c.votes=votes[i];
				if(wishList[i]==-1)
					v.push_back(c);
				else
					candiates[wishList[i]]=c;
			}

			sort(v.begin(),v.end(),greater<CAND>());
			for(int i=0;i<(int)v.size();i++)
				for(int j=0;j<n;j++)
					if(candiates[j].id==-1)
					{
						candiates[j]=v[i];
						break;
					}

			int ans=0;
			for(int i=n-1;0<i;i--)
			{
					if(candiates[i-1].votes<candiates[i].votes)
					{
						ans+=candiates[i].votes-candiates[i-1].votes;
						candiates[i-1].votes=candiates[i].votes;
					}

					if(candiates[i-1].votes==candiates[i].votes &&
							candiates[i-1].id>candiates[i].id)
					{
						ans+=1;
						candiates[i-1].votes+=1;
					}
			}

			return ans;
		}
};


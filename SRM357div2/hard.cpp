#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <sstream>
#include <utility>

using namespace std;
typedef long long LL;

class WebsiteRank
{
	public:

		int n;
		bool G[1000][1000];
		bool H[1000][1000];
		vector<LL> weight;
		set<string> siteToNum;

		int sToN(string s)
		{
			return (int)distance(siteToNum.begin(),siteToNum.find(s));
		}

		LL rec(int index)
		{
			LL &r=weight[index];
			if(r!=-1)
				return r;

			r=1;
			for(int i=0;i<n;i++)
				if(G[index][i])
					r+=rec(i);

			return r;
		}

		LL countVotes(vector <string> votes, string website)
		{
			vector<vector<string> > input(votes.size());
			for(int i=0;i<(int)votes.size();i++)
			{
				stringstream ss(votes[i]);
				string s;
				while(ss >> s)
				{
					input[i].push_back(s);
					siteToNum.insert(s);
				}
			}

			n=siteToNum.size();

			memset(G,false,sizeof(G));
			memset(H,false,sizeof(H));
			for(int i=0;i<(int)votes.size();i++)
			{
				string s=input[i][0];
				int a=sToN(s);
				for(int j=1;j<input[i].size();j++)
				{
					int b=sToN(input[i][j]);
					G[a][b]=H[a][b]=true;
				}
			}

			for(int i=0;i<n;i++)
				G[i][i]=H[i][i]=true;
			for(int k=0;k<n;k++)
				for(int i=0;i<n;i++)
					for(int j=0;j<n;j++)
							H[i][j]=(H[i][j] || (H[i][k]&&H[k][j]) );
							
			for(int i=0;i<n;i++)
				for(int j=i;j<n;j++)
					if(H[i][j] && H[j][i])
						G[i][j]=G[j][i]=false;
			
			weight=vector<LL>(n,-1);

			return rec(sToN(website));
		}
};

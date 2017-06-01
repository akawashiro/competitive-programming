#include <vector>
#include <string>
using namespace std;
typedef long long LL;

class SubrectanglesOfTable
{
	public:
		vector<long long> getQuantity(vector <string> table)
		{
			for(int i=0;i<table.size();i++)
				table[i]+=table[i];
			vector<string> t=table;
			table.insert(table.end(),t.begin(),t.end());

			int h=table.size(),w=table[0].size();
			vector<vector<LL> > freq(h,vector<LL>(w));
			vector<LL> ans;

			for(LL i=0;i<h;i++)
				for(LL j=0;j<w;j++)
					freq[i][j]=(i-0+1)*(h-i)*(j-0+1)*(w-j);
			for(char c='A';c<='Z';c++)
			{
				LL a=0;
				for(int i=0;i<h;i++)
					for(int j=0;j<w;j++)
						if(table[i][j]==c)
							a+=freq[i][j];
				ans.push_back(a);
			}
			return ans;
		}
};

#include <sstream>
#include <string>
#include <vector>

using namespace std;

class IncompleteBST
{
	public:

		char tree[(1<<20)];

		bool rec(int cur,char bottom,char ceil)
		{
			if((1<<20)<=cur || tree[cur]=='#')
				return true;
			if(tree[cur]<bottom || ceil<tree[cur])
				return false;
			return rec(cur*2,bottom,min(ceil,tree[cur])) && rec(cur*2+1,max((char)(tree[cur]+1),bottom),ceil);
		}

		string missingValues(vector<string> _tree)
		{
			int q=0;
			for(int i=0;i<(1<<20);i++)
				tree[i]='#';
			for(int i=0;i<(int)_tree.size();i++)
			{
				stringstream ss(_tree[i]);
				char d;
				int n;
				ss >> d >> n;
				tree[n]=d;
				if(d=='?')
					q=n;
			}

			string ans;
			for(char c='A';c<='Z';c++)
			{
				tree[q]=c;
				if(rec(1,'A','Z'))
					ans+=c;
			}

			return ans;
		}
};


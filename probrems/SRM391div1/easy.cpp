#include <string>
#include <vector>
using namespace std;

class IsomorphicWords
{
	public:

		string tr(string s)
		{
			string r;
			char table[256];
			for(int i=0;i<256;i++)
				table[i]='?';
			char c='a';
			for(int i=0;i<(int)s.size();i++)
				if(table[s[i]]=='?')
				{
					table[s[i]]=c;
					c++;
				}
			for(int i=0;i<(int)s.size();i++)
				r+=table[s[i]];
			return r;
		}

		int countPairs(vector <string> words)
		{
			int n=(int)words.size();
			for(int i=0;i<n;i++)
				words[i]=tr(words[i]);

			int ans=0;
			for(int i=0;i<n;i++)
				for(int j=i+1;j<n;j++)
					if(words[i]==words[j])
						ans++;

			return ans;
		}
};


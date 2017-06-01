#include <string>
#include <vector>

using namespace std;

class Teaching
{
	public:

		int popCount(int n)
		{
			int r=0;
			for(int i=0;i<30;i++)
				if(n & (1<<i))
					r++;
			return r;
		}

		bool acint(char c)
		{
			return (c=='a' || c=='c' || c=='i' || c=='n' || c=='t');
		}

		int c2i(char c)
		{
			int abc[26],r=0;
			for(int i=0;i<26;i++)
				abc[i]=(acint('a'+i))?0:1;
			for(int i=0;i<=c-'a';i++)
				r+=abc[i];
			return r-1;
		}

		int count(vector <string> words, int K)
		{
			int n=words.size();
			if(K<5)
				return 0;
			K-=5;

			vector<int> w(n,0);
			for(int i=0;i<n;i++)
				for(int j=0;j<(int)words[i].size();j++)
					if(!acint(words[i][j]))
							w[i]|=(1<<c2i(words[i][j]));

			int ans=0;
			for(int learn=0;learn<(1<<21);learn++)
				if(popCount(learn)==K)
				{
					int aa=0;
					for(int i=0;i<n;i++)
						if((w[i]&learn)==w[i])
							aa++;
					ans=max(ans,aa);
				}

			return ans;
		}
};


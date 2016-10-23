#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class WordsGame{
	public:

		int check(string from,string to)
		{
			int n=from.size(),c;
			for(c=0;;c++)
			{
				int t;
				for(t=0; t<n && from[t]=='_'; t++)
					;
				if(t==n)
					break;
				while(from[t]!='_')
				{
					int p=t;
					t=to.find(from[t]);
					if(t==string::npos)
						return n;
					from[p]=to[t]='_';
				}
			}
			return n-c;
		}

		int minimumSwaps(vector <string> grid, string word)
		{
			int N=grid.size(),ans=grid.size();
			string sWord=word;
			vector<string> possible;
			
			sort(sWord.begin(),sWord.end());

			for(int i=0;i<N;i++){
				string s=grid[i];
				sort(s.begin(),s.end());
				if(s == sWord)
					possible.push_back(grid[i]);
			}
			for(int i=0;i<N;i++)
			{
				string s1,s2;
				for(int j=0;j<N;j++)
					s1+=grid[j][i];
				s2=s1;
				sort(s2.begin(),s2.end());
				if(s2 == sWord)
					possible.push_back(s1);
			}

			for(int i=0;i<possible.size();i++)
				ans=min(ans,check(word,possible[i]));

			return (ans==N) ? -1 : ans;
		}
};

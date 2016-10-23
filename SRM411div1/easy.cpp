#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <map>
#include <cstdio>
using namespace std;

class SentenceDecomposition
{
	public:
		string sentence;
		int n;
		vector<string> valid;
		int cache[100];

		bool canTrance(string s,string t)
		{
			sort(s.begin(),s.end());
			sort(t.begin(),t.end());
			return (s==t);
		}

		int cost(int b)
		{
			if(b==n)
				return cache[b]=0;
			if(cache[b]!=-2)
				return cache[b];
			
			int r=INT_MAX;
			for(int i=0;i<valid.size();i++)
			{
				int vn=valid[i].size();
				if( vn<=n-b+1 )
				{
					string s=sentence.substr(b,vn);
					if(canTrance(s,valid[i]) )
					{
						int a=0;
						for(int j=0;j<vn;j++)
							if(s[j]!=valid[i][j])
								a++;
						int c=cost( b+vn ) ;
						if(c!=INT_MAX)
							r=min(r,a+c);
					}
				}
			}
			
			return cache[b]=r;
		}

		int decompose(string _sentence, vector <string> _valid)
		{
			valid=_valid;
			sentence=_sentence;
			n=sentence.size();


			for(int i=0;i<n;i++)
			{
				cache[i]=-2;
				//printf("cache[%d]=%d\n",i,cache[i]);
			}
			
			int ans=cost(0);
			
			//for(int i=0;i<n;i++)
			//	printf("cache[%d]=%d\n",i,cache[i]);
				
			return (ans==INT_MAX) ? -1 : ans;
		}
};

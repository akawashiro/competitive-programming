#include <string>
#include <vector>
#include <algorithm>

typedef long long LL;
using namespace std;

class AnagramList
{
	public:

		LL fact(LL n)
		{
			LL r=1;
			for(LL i=1;i<=n;i++)
				r*=i;
			return r;
		}

		LL perm(string s)
		{
			LL r=fact((LL)s.size());
			for(char c='a';c<='z';c++)
			{
				LL a=0;
				for(int i=0;i<(int)s.size();i++)
					if(s[i]==c)
						a++;
				r/=fact(a);
			}
			return r;
		}

		string rec(string source,LL index)
		{
			LL num=0;
			for(int i=0;i<(int)source.size();i++)
			{
				if(0<i && source[i-1]==source[i])
					continue;

				string s;
				for(int j=0;j<source.size();j++)
					if(j!=i)
						s+=source[j];

				LL l=perm(s);
				if(num<=index && index<num+l)
					return source[i]+rec(s,index-num);
				num+=l;
			}
			return "";
		}

		string getAnagram(string s, int i)
		{
			sort(s.begin(),s.end());
			string ans=rec(s,(LL)i);
			if(s.size()!=ans.size())
				return "";
			return ans;
		}
};


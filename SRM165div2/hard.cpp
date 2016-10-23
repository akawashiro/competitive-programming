#include <string>
using namespace std;

class ShortPalindromes{
	public:

		string dp[25][25];
		string origin;

		string rec(int b,int e)
		{
			if(dp[b][e]!="")
				return dp[b][e];

			string s=origin.substr(b,e-b+1);

			if(s.size()==0)
				return "";
			if(s.size()==1)
				return s;

			bool isPali=true;
			for(int i=0;i<s.size();i++)
				if(s[i]!=s[s.size()-1-i])
					isPali=false;
			if(isPali){
				dp[b][e]=s;
				return s;
			}
			if(s[0]==s[s.size()-1]){
				dp[b][e]=(s[0]+rec(b+1,e-1)+s[0]);
				return dp[b][e];
			}

			string s1,s2,r;
			s1=(s[0]+rec(b+1,e)+s[0]);
			s2=(s[s.size()-1]+rec(b,e-1)+s[s.size()-1]);
			if(s1.size()<s2.size())
				r=s1;
			else if(s2.size()<s1.size())
				r=s2;
			else
				r=(s1<s2) ? s1 :s2;
			dp[b][e]=r;
			return r;
		}

		string shortest(string base)
		{
			origin=base;
			return rec(0,base.size()-1);
		}
};

#include <string>
using namespace std;

class TemplateMatching
{
	public:
		int returnP,returnS;
		void score(string S,string pre,string suf)
		{
			int p,s;
			for(p=min(S.size(),pre.size());0<p;p--)
				if(S.substr(0,p)==pre.substr(pre.size()-p,p))
					break;
			for(s=min(S.size(),suf.size());0<s;s--)
				if(S.substr(S.size()-s,s)==suf.substr(0,s))
					break;
			returnP=p,returnS=s;
		}

		string bestMatch(string text, string prefix, string suffix)
		{
			int maxScore=-1,maxP=-1;
			string ans;
			for(int i=0;i<text.size();i++)
				for(int j=i;j<text.size();j++)
				{
					string S=text.substr(i,j-i+1);
					score(S,prefix,suffix);
					if(maxScore<returnP+returnS)
					{
						ans=S;
						maxScore=returnP+returnS;
						maxP=returnP;
					}
					else if(maxScore==returnP+returnS)
					{
						if(maxP<returnP)
						{
							ans=S;
							maxP=returnP;
						}
						else
							ans=min(ans,S);
					}
				}
			return ans;
		}
};

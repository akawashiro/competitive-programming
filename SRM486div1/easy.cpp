#include <string>
using namespace std;
typedef long long LL;

class OneRegister
{
	public:
		string ans;

		bool cmp(string s,string t) // s<t?
		{
			//printf("cmp start\n");
			if(s.size()!=t.size())
			{
				//printf("cmp end\n");
				return s.size()<t.size();
			}
			for(int i=0;i<s.size();i++)
				if(s[i]!=t[i])
				{
					//printf("cmp end\n");
					return s[i]<t[i];
				}
			//printf("cmp end\n");
			return true;
		}

		void f(string prog,LL s,LL t)
		{
			if(t<s)
				return;
			if(s==t)
				ans=(cmp(prog,ans)) ? prog : ans;
			if(s*2==t)
				ans=(cmp(prog+"+",ans)) ? prog+"+" : ans;
			if(s*s==t)
				ans=(cmp(prog+"*",ans)) ? prog+"*" : ans;
			f(prog+"+",s*2,t);
			if(s!=1)
				f(prog+"*",s*s,t);

		}

		string getProgram(int s, int t)
		{
			if(s==t)
				return "";
			if(t==0)
				return "-";
			if(t==1)
				return "/";
			ans=string(100,'N');
			//printf("%s",ans.c_str());

			f("",(LL)s,(LL)t);
			f("/+",2,(LL)t);

			return (ans.size()==100) ? ":-(" : ans;
		}
};

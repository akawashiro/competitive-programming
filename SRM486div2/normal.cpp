#include <string>
using namespace std;

class OneRegister{
		public:
				string getProgram(int s, int t);
};

string whichtoreturn(string a,string b)
{
		if(a.size()<b.size())
				return a;
		if(b.size()<a.size())
				return b;
		return min(a,b);
}

string caluc(long long s,long long t)
{
		if(s==t)
				return "";
		if(t<s)
				return string(100,'w');
		if(s==1)
				return "+"+caluc(s+s,t);
		return whichtoreturn("+"+caluc(s+s,t),"*"+caluc(s*s,t));
}

string OneRegister::getProgram(int s,int t)
{
		string ans=whichtoreturn(caluc(s,t),"/"+caluc(1,t));
		return (ans.size()<100) ? ans : ":-(";
}


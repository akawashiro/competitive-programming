#include <string>
#include <iostream>
using namespace std;

void solve(string s)
{
	for(int i=0;i<26;i++)
	{
		string t=s;
		for(int j=0;j<t.size();j++)
			if('a'<=t[j] && t[j]<='z')
				t[j]=(t[j]-'a'+i)%26+'a';
		if(t.find("this")!=string::npos || t.find("that")!=string::npos 
				|| t.find("the")!=string::npos)
		{
			cout << t << endl;
			return;
		}
	}
}

int main()
{
	string s;
	while(getline(cin,s))
		solve(s);
	return 0;
}


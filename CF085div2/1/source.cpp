#include <string>
#include <iostream>

using namespace std;

int main()
{
	string s,t,ss,tt;
	cin>>s>>t;
	for(int i=0;i<s.size();i++)
		s[i]=('A'<=s[i] && s[i]<='Z')?(s[i]-'A'+'a'):s[i];
	for(int i=0;i<t.size();i++)
		t[i]=('A'<=t[i] && t[i]<='Z')?(t[i]-'A'+'a'):t[i];
	if(s==t)
		cout<<"0"<<endl;
	else if(s<t)
		cout<<"-1"<<endl;
	else
		cout<<"1"<<endl;
	return 0;
}


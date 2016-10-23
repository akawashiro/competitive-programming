#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin>>s;
	int n=s.size(),ans=0;
	if(n%2==1 && s[n/2]!='i' && s[n/2]!='w')
		ans++;
	for(int b=0,e=n-1;b<e;b++,e--)
	{
		char o;
		if(s[b]=='w')
			o='w';
		else if(s[b]=='i')
			o='i';
		else if(s[b]=='(')
			o=')';
		else if(s[b]==')')
			o='(';
		else
			;
		if(s[e]!=o)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}


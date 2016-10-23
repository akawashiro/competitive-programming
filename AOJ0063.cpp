#include <string>
#include <iostream>

using namespace std;

int main()
{
	int ans=0;
	string s;
	while(cin>>s)
	{
		int i;
		for(i=0;i<s.size();i++)
			if(s[i]!=s[s.size()-1-i])
				break;
		if(i==s.size())
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}


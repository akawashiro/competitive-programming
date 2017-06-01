#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int ans=0;
	string s;
	while(cin>>s){
		for(int i=0;i<s.size();i++)
			if('0'<=s[i] && s[i]<='9')
				;
			else
				s[i]=' ';
		stringstream ss(s);
		int a;
		while(ss>>a)
			ans+=a;
	}
	cout<<ans<<endl;
	return 0;
}


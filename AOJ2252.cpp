#include <string>
#include <iostream>

using namespace std;

int isRight(char c)
{
	string r="yuiophjklnm";
	for(int j=0;j<r.size();j++)
		if(r[j]==c)
			return 1;
	return 0;
}

int main()
{
	while(1)
	{
		int ans=0;
		string s;
		cin>>s;
		if(s=="#")
			return 0;
		for(int i=0;i<s.size()-1;i++)
			ans+=isRight(s[i])^isRight(s[i+1]);
		cout<<ans<<endl;
	}
}


#include <string>
#include <iostream>
#include <set>

using namespace std;
int start[2000+10];
int end[2000+10];

int main()
{
	string t,sbegin,send;
	cin>>t>>sbegin>>send;
	for(int i=0;i<t.size() && i+sbegin.size()<=t.size();i++)
	{
		int j;
		for(j=0;j<sbegin.size();j++)
			if(t[i+j]!=sbegin[j])
				break;
		if(j==sbegin.size())
			start[i]=1;
	}
	for(int i=0;i<t.size() && i+send.size()<=t.size();i++)
	{
		int j;
		for(j=0;j<send.size();j++)
			if(t[i+j]!=send[j])
				break;
		if(j==send.size())
			end[i]=1;
	}
	set<string> se;
	for(int i=0;i<t.size();i++)
	{
		if(start[i]==1)
			for(int j=i;j<t.size();j++)
				if(end[j]==1)
					se.insert(t.substr(i,j-i+1));
	}
	cout<<se.size()<<endl;
	return 0;
}


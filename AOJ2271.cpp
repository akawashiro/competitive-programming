#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin>>s;
	int K=0,U=0,P=0,C=0;
	for(int i=0;i<s.size();i++)
		if(s[i]=='K')
			K++;
		else if(s[i]=='U')
			U++;
		else if(s[i]=='P')
			P++;
		else if(s[i]=='C')
			C++;
	cout<<min(min(K,U),min(P,C))<<endl;
	return 0;
}


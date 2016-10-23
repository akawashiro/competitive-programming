#include <string>
#include <iostream>
using namespace std;
int ar[30];
int main(){
	string s;
	cin>>s;
	for(int i=0;i<(int)s.size();i++)
		ar[s[i]-'A']--;
	cin>>s;
	for(int i=0;i<(int)s.size();i++)
		ar[s[i]-'A']--;
	cin>>s;
	for(int i=0;i<(int)s.size();i++)
		ar[s[i]-'A']++;
	int ok=1;
	for(int i=0;i<30;i++)
		if(ar[i]!=0)
			ok=0;
	if(ok)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}


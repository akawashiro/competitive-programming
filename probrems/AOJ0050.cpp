#include <string>
#include <iostream>
using namespace std;
int main(){
	string s;
	getline(cin,s);
	for(int i=0;i<(int)s.size()-4;i++)
		if(s.substr(i,5)=="peach")
			s[i]='a',s[i+1]='p',s[i+2]='p',s[i+3]='l',s[i+4]='e';
		else if(s.substr(i,5)=="apple")
			s[i]='p',s[i+1]='e',s[i+2]='a',s[i+3]='c',s[i+4]='h';
	cout<<s<<endl;
	return 0;
}


//AOJ0077
#include <string>
#include <iostream>
using namespace std;
int main(){
	string s;
	while(cin>>s){
		string t;
		int n=s.size();
		for(int i=0;i<n;i++)
			if(s[i]=='@'){
				t+=string(s[i+1]-'0',s[i+2]);
				i+=2;
			}else
				t+=s[i];
			cout<<t<<endl;
	}
	return 0;
}


//AOJ0101
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	getline(cin,s);
	for(int i=0;i<n;i++){
		getline(cin,s);
		int m=s.size();
		for(int j=0;j+6<m;j++)
			if(s.substr(j,7)=="Hoshino")
				s[j+6]='a';
		cout<<s<<endl;
	}
	return 0;
}


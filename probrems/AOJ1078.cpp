//AOJ1078.cpp
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;
int main(){
	while(1){
		string a,b,c,d;
		if(!(cin>>d))	break;
		if(d=="#")	break;
		for(int i=0;i<(int)d.size();i++)
			if(d[i]=='('||d[i]==')'||d[i]=='|'||d[i]=='&')
				d[i]=' ';
		stringstream ss(d);
		string ans="no";
		while(ss>>a>>b>>c){
			if(a!="~"+b&&a!="~"+c&&b!="~"+a&&b!="~"+c&&c!="~"+a&&c!="~"+b)
				ans="yes";
		}
		cout<<ans<<endl;
	}
	return 0;
}


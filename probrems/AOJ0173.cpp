//AOJ0173
#include <string>
#include <iostream>
using namespace std;
int main(){
	for(int i=0;i<9;i++){
		string s;
		int a,b,c;
		cin>>s>>a>>b;
		c=a*200+b*300;
		cout<<s<<" "<<a+b<<" "<<c<<endl;
	}
	return 0;
}


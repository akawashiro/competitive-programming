//AOJ0127
#include <string>
#include <iostream>
using namespace std;
int main(){
	string ch="abcdefghijklmnopqrstuvwxyz.?! ";
	string s;
	while(cin>>s){
		int n=s.size(),b=(n%2==0);
		for(int i=0;i<n;i++)
			if(i%2==0){
				if(!('1'<=s[i]&&s[i]<='6'))
					b=0;
			}else{
				if(!('1'<=s[i]&&s[i]<='5'))
					b=0;
			}
		if(b){
			for(int i=0;i<n;i+=2){
				//cout<<(s[i]-'1')*5<<"-"<<s[i+1]-'1'<<endl;
				//cout<<(s[i]-'1')*5+s[i+1]-'1'<<endl;
				cout<<ch[(s[i]-'1')*5+s[i+1]-'1'];
			}
			cout<<endl;
		}else{
			cout<<"NA"<<endl;
		}
	}
	return 0;
}


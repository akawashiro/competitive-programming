//AOJ0139
#include <string>
#include <iostream>
using namespace std;
int isA(string s){
	int n=s.size();
	if(n<6)	return 0;
	int e=(n-4)/2;
	string t=">'"+string(e,'=')+'#'+string(e,'=')+'~';
	return s==t;
}
int isB(string s){
	int n=s.size();
	if(n<6)	return 0;
	string t=">^";
	for(;t.size()<n-2;)
		t+="Q=";
	t+="~~";
	return s==t;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		if(isA(s))	cout<<"A"<<endl;
		if(isB(s))	cout<<"B"<<endl;
		if(!isA(s)&&!isB(s))	cout<<"NA"<<endl;
	}
	return 0;
}


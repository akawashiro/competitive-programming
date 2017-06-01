//AOJ0175
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
string conv(int n){
	string res;
	while(n!=0){
		res+='0'+n%4;
		n/=4;
	}
	reverse(res.begin(),res.end());
	if(res=="")
		res="0";
	return res;
}
int main(){
	int n;
	while(1){
		cin>>n;
		if(n==-1)
			break;
		if(n<0)
			cout<<"-"<<conv(-n)<<endl;
		else
			cout<<conv(n)<<endl;
	}
	return 0;
}


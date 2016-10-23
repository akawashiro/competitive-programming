#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	int n,ok;
	string s;
	cin>>n>>s;
	ok=(count(s.begin(),s.end(),'4')+count(s.begin(),s.end(),'7')==n);
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=(i<n/2)?s[i]-'0':-s[i]+'0';
	if(!sum==0)
		ok=0;
	if(ok)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}


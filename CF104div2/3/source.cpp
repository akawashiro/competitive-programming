#include <string>
#include <iostream>
using namespace std;
int ABS(int n){
	if(n<0)	return -n;
	else	return n;
}
int main(){
	int n;
	string a,b;
	cin>>a>>b;
	n=a.size();
	int s=0,f=0;
	for(int i=0;i<n;i++){
		if(a[i]=='4'&&a[i]!=b[i])	f++;
		if(a[i]=='7'&&a[i]!=b[i])	s++;
	}
	int ans=0;
	int sw=min(s,f);
	ans=sw+f-sw+s-sw;
	cout<<ans<<endl;
	return 0;
}


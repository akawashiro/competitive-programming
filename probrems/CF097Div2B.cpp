//CF097Div2B
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
//algorithm,string
string tenToN(int b,int n){
	if(n==0)
		return "0";
	string r;
	while(0<n){
		r+=n%b+'0';
		n/=b;
	}
	reverse(r.begin(),r.end());
	return r;
}
int NtoTen(int b,string n){
	int r=0;
	for(int i=(int)n.size()-1,t=1;0<=i;i--,t*=b)
		r+=(n[i]-'0')*t;
	return r;
}
int main(){
	int a,b,c;
	string sa,sb,sc;
	cin>>a>>c;
	sa=tenToN(3,a),sc=tenToN(3,c);
	int n=max(sa.size(),sc.size());
	//cout<<sa<<" "<<sc<<endl;
	sa=string(n-sa.size(),'0')+sa;
	sb=string(n,'0');
	sc=string(n-sc.size(),'0')+sc;
	for(int i=0;i<n;i++)
		sb[i]=(sc[i]-sa[i]+3)%3+'0';
	//cout<<sb<<endl;
	b=NtoTen(3,sb);
	cout<<b<<endl;
	return 0;
}


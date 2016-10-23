//AOJ1142
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main(){
	int T;
	cin>>T;
	for(;0<T;T--){
		string tr;
		set<string> se;
		cin>>tr;
		int n=tr.size();
		for(int i=1;i<n;i++){
			string s=tr.substr(0,i);
			string t=tr.substr(i);
			string ss=s,tt=t;
			reverse(ss.begin(),ss.end());
			reverse(tt.begin(),tt.end());
			se.insert(s+t);
			se.insert(s+tt);
			se.insert(ss+t);
			se.insert(ss+tt);
			se.insert(t+s);
			se.insert(t+ss);
			se.insert(tt+s);
			se.insert(tt+ss);
		}
		cout<<se.size()<<endl;
	}
	return 0;
}


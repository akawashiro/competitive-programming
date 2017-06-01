//AOJ0179
#include <string>
#include <queue>
#include <set>
#include <map>
#include <iostream>
#include <limits.h>
using namespace std;
/*int rec(string s){
	cout<<s<<endl;
	if(ma.find(s)!=ma.end())
		return (ma[s]!=-1)?ma[s]:INT_MAX/2;
	int i;
	for(i=0;i<n-1;i++)
		if(s[i]!=s[i+1])
			break;
	if(i==n-1)
		return ma[s]=0;
	int res=INT_MAX/2;
	ma[s]=-1;
	for(i=0;i<n-1;i++)
		if(s[i]!=s[i+1]){
			int c='r'+'g'+'b'-s[i]-s[i+1];
			string t=s;
			t[i]=t[i+1]=c;
			res=min(res,rec(t)+1);
		}
	return ma[s]=res;
}*/
int main(){
	while(1){
		int n;
		set<string> se;
		queue<string> qs;
		queue<int> qi;
		string s;
		cin>>s;
		if(s=="0")
			break;
		n=s.size();
		int ans=-1;
		qs.push(s);
		qi.push(0);
		while(!qs.empty()){
			s=qs.front();
			int a=qi.front();
			qs.pop();
			qi.pop();
			if(se.find(s)!=se.end())
				continue;
			//cout<<s<<endl;
			se.insert(s);
			int i;
			for(i=0;i<n-1;i++)
				if(s[i]!=s[i+1])
					break;
			if(i==n-1){
				ans=a;
				break;
			}
			for(i=0;i<n-1;i++)
				if(s[i]!=s[i+1]){
					int c='r'+'g'+'b'-s[i]-s[i+1];
					string t=s;
					t[i]=t[i+1]=c;
					qs.push(t);
					qi.push(a+1);
				}
		}
		if(ans==-1)
			cout<<"NA"<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}

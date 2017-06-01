//AOJ1111
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int match(string &s,string t){
	for(int i=0;i<8;i++)
		if(s[i]!='?'&&s[i]!=t[i])
			return 0;
	return 1;
}
int main(){
	while(1){
		int n,m;
		cin>>n>>m;
		if(!n&&!m)	break;
		vector<int> isP;
		vector<string> so,de;
		for(int i=0;i<n;i++){
			string p,s,d;
			cin>>p>>s>>d;
			isP.push_back((p=="permit"));
			so.push_back(s);
			de.push_back(d);
		}
		vector<string> rso,rde,rme;
		for(int i=0;i<m;i++){
			string s,d,t;
			cin>>s>>d>>t;
			int b=0;
			for(int j=0;j<n;j++)
				if(match(so[j],s)&&match(de[j],d))
					b=isP[j];
			if(b){
				rso.push_back(s);
				rde.push_back(d);
				rme.push_back(t);
			}
		}
		cout<<rso.size()<<endl;
		for(int i=0;i<(int)rso.size();i++)
			cout<<rso[i]<<" "<<rde[i]<<" "<<rme[i]<<endl;
	}
	return 0;
}


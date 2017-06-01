//AOJ1305
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;
map<string,vector<string> > ma;
set<string> se,se2;
void rec(string s){
	if(se2.find(s)!=se2.end())
		return;
	else{
		se2.insert(s);
		if(ma.find(s)==ma.end())
			se.insert(s);
		else
			for(int i=0;i<(int)ma[s].size();i++)
				rec(ma[s][i]);
	}
}
int main(){
	while(1){
		int n;
		cin>>n;
		if(!n)	break;
		string query;
		ma.clear();
		for(int i=0;i<n;i++){
			string s,t;
			cin>>s;
			replace(s.begin(),s.end(),':',' ');
			replace(s.begin(),s.end(),',',' ');
			replace(s.begin(),s.end(),'.',' ');
			stringstream ss(s);
			ss>>s;
			if(i==0)	query=s;
			while(ss>>t)
				ma[s].push_back(t);
		}
		se.clear();
		se2.clear();
		rec(query);
		cout<<se.size()<<endl;;
	}
	return 0;
}


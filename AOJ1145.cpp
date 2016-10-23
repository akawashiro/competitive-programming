//AOJ1145
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;
int stoi(string s){stringstream ss(s);int r;ss>>r;return r;}
int isAlpha(int c){	return ('A'<=c&&c<='Z');	};
int isNum(int c)  {	return ('0'<=c&&c<='9');	};
int pos;
string result;
map<string,string> ma;
string parse(string so){
	if(ma.find(so)!=ma.end()){
		result+=ma[so];
		return ma[so];
	}
	int n=so.size();
	vector<string> vs;
	for(int i=0;i<n;){
		string s,t;
		if(isAlpha(so[i])){
			for(;i<n&&isAlpha(so[i]);i++)	s+=so[i];
			vs.push_back(s);
		}else{
			int c=0;
			for(;i<n&&isNum(so[i]);i++)	s+=so[i];
			if(isAlpha(so[i])){
				for(;i<n&&isAlpha(so[i]);i++)t+=so[i];
			}else{
				c=1,i++;
				while(1){
					if(so[i]=='(')	c++;
					if(so[i]==')')	c--;
					if(c==0)		break;
					t+=so[i];
					i++;
				}
				i++;
			}
			vs.push_back(s);
			vs.push_back(t);
		}
	}
	string r;
	for(int i=0;i<vs.size();i++){
		if(pos<result.size())	return "";
		if(isAlpha(vs[i][0])){	result+=vs[i];r+=vs[i];	}
		if(isNum(vs[i][0])){
			int a=stoi(vs[i]);
			i++;
			for(int j=0;j<a;j++){
				if(pos<result.size())
					return "";
				r+=parse(vs[i]);
			}
		}
	}
	return ma[so]=r;
}
int main(){
	string s;
	while(1){
		cin>>s>>pos;
		if(s=="0"&&pos==0)	break;
		result="";
		ma.clear();
		parse(s);
		if(pos<result.size())	cout<<result[pos]<<endl;
		else	cout<<"0"<<endl;
	}
	return 0;
}


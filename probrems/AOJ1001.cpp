//AOJ1001
#include <string>
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int main(){
	while(1){
		string type,s,t,ans;
		if(!(cin>>type))	break;
		cin>>s>>t;
		vector<int> v,u;
		int a=0;
		for(int i=0;i<(int)s.size();i++){
			if(s[i]=='('){	a++,v.push_back(a);}
			else if(s[i]==')'){	v.push_back(a),a--;}
			else{	v.push_back(a);	}
			//cout<<a<<" ";
		}
		//cout<<endl;
		a=0;
		for(int i=0;i<(int)t.size();i++){
			if(t[i]=='('){	a++;u.push_back(a);	}
			else if(t[i]==')'){	u.push_back(a);a--;	}
			else 		 {	u.push_back(a);		}
			//cout<<a<<" ";
		}
		//cout<<endl;
		if(type=="i"){
			int i=0,j=0;
			while(i<(int)s.size()&&j<(int)t.size()){
				if(v[i]==u[j]){
					ans+=s[i];
					i++,j++;
				}else if(v[i]<u[j]){
					j++;
				}else{
					i++;
				}
			}
		}else{
			int i=0,j=0;
			while(i<(int)s.size()&&j<(int)t.size()){
				//cout<<i<<" "<<j<<endl;
				//cout<<ans<<endl;
				if(v[i]==u[j]){
					ans+=s[i];
					i++,j++;
				}else if(v[i]<u[j]){
					ans+=t[j];
					j++;
				}else{
					ans+=s[i];
					i++;
				}
			}
		}		
		cout<<ans<<endl;
	}
	return 0;
}


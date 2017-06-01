//AOJ1173
#include <string>
#include <stack>
#include <iostream>
using namespace std;
int main(){
	while(1){
		string s;
		getline(cin,s);
		if(s==".")
			break;
		int b=1;
		stack<int> st;
		for(int i=0;i<(int)s.size();i++){
			if(s[i]=='('){
				st.push('(');
			}else if(s[i]=='['){
				st.push('[');
			}else if(s[i]==')'){
				if(!st.empty()&&st.top()=='(')
					st.pop();
				else
					b=0;
			}else if(s[i]==']'){
				if(!st.empty()&&st.top()=='[')
					st.pop();
				else
					b=0;
			}
		}
		if(!st.empty())
			b=0;
		if(b)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}


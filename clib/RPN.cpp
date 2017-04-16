inline bool isConst(char c){
     return ('A'<=c&&c<='B');
}

inline int priority(char c){
     return (c=='c')?1:0;
}

string toRPN(string so){
     stack<pair<char,int> > st;
     string res;
     int par=0;
     for(int i=0;i<SZ(so);i++){
	  if(isConst(so[i]))res+=so[i];
	  else if(so[i]=='(')par+=2;
	  else if(so[i]==')')par-=2;
	  else{
	       while(!st.empty()&&priority(so[i])+par<st.top().second){
		    res+=st.top().first;
		    st.pop();
	       }
	       st.push(make_pair(so[i],priority(so[i])+par));
	  }
     }
     while(!st.empty()){
	  res+=st.top().first;
	  st.pop();
     }
     return res;
}

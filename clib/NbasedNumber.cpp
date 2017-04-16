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


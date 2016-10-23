//AOJ2105
#include <string>
#include <iostream>
#include <vector>
using namespace std;
int gcd(int x,int y){
	if(y==0)	return x;
	else	return gcd(y,x%y);
}
int lcm(int x,int y){
	return x/gcd(x,y)*y;
}
vector<int> compress(vector<int> &v){
	int n=v.size();
	vector<int> r;
	for(int l=n;0<l;l--)
		if(n%l==0){
			int b=1;
			vector<int> t;
			for(int i=0;i<n;i++){
				if(i%l==0)	
					t.push_back(v[i]);
				if(i%l!=0&&v[i]!=0){
					b=0;
					break;
				}
			}
			if(b){
				r=t;
				break;
			}
		}
	return r;
}
int main(){
	int T;
	cin>>T;
	for(;0<T;T--){
		int n,len=1;
		cin>>n;
		vector<vector<int> > R;
		for(int i=0;i<n;i++){
			string s;
			vector<int> v;
			cin>>s;
			for(int j=0;j<(int)s.size();j+=2){
				int a=(s[j]-'0')*16+(s[j+1]-'0');
				v.push_back(a);
			}
			R.push_back(compress(v));
			if(len<=1024)
				len=lcm(len,(int)R[i].size());
		}
		if(len<=1024){
			vector<int> ans(len,0);
			for(int i=0;i<n;i++){
				int m=R[i].size();
				for(int j=0;j<m;j++)
					ans[j*len/m]+=R[i][j];
			}
			for(int i=0;i<len;i++){
				int a=ans[i]/16;
				if(a<10)	cout<<a;
				else		cout<<(char)(a-10+'A');
				int b=ans[i]%16;
				if(b<10)	cout<<b;
				else		cout<<(char)(b-10+'A');
			}
			cout<<endl;
		}else{
			cout<<"Too complex."<<endl;
		}
	}
	return 0;
}

				
















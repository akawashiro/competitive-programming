//AOJ2242
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
int main(){
	while(1){
		int n,m;
		cin>>n>>m;
		if(!n&&!m)	break;
		vector<string> era(n);
		vector<int> v(n),x(n);
		for(int i=0;i<n;i++)
			cin>>era[i]>>v[i]>>x[i];
		for(int i=0;i<m;i++){
			string r="Unknown";
			int a=-1;
			int q;
			cin>>q;
			for(int j=0;j<n;j++)
				if(x[j]-v[j]<q&&q<=x[j]){
					a=q-x[j]+v[j];
					r=era[j];
				}
			if(r=="Unknown")
				cout<<r<<endl;
			else
				cout<<r<<" "<<a<<endl;
		}
	}
	return 0;
}


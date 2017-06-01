//AOJ0170
#include <string>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	while(1){
		int n;
		cin>>n;
		if(!n)
			break;
		vector<string> f(n);
		vector<int> w(n),s(n),ans,o;
		int g=1000000;
		for(int i=0;i<n;i++){
			o.push_back(i);
			cin>>f[i]>>w[i]>>s[i];
		}
		do{
			int b=1,ss=0,gg=0;
			for(int i=n-1;0<=i;i--){
				if(s[o[i]]<ss)
					b=0;
				ss+=w[o[i]];
				gg+=(i+1)*w[o[i]];
			}
			/*printf("b=%d gg=%d\n",b,gg);
			fflush(stdout);*/
			if(b&&gg<g){
				/*for(int i=0;i<n;i++)
					cout<<o[i]<<" ";
				cout<<endl;*/
				g=gg;
				ans=o;
			}
		}while(next_permutation(o.begin(),o.end()));
		for(int i=0;i<n;i++)
			cout<<f[ans[i]]<<endl;
	}
	return 0;
}


//AOJ0124
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
int main(){
	for(int t=0;;t++){
		int n;
		vector<pair<int,string> > vp;
		cin>>n;
		if(!n)
			break;
		for(int i=0;i<n;i++){
			string s;
			int a,b,c,d=0;
			cin>>s>>a>>b>>c;
			d=a*3+c;
			vp.push_back(make_pair(d,s));
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n-1;j++)
				if(vp[j].first<vp[j+1].first)
					swap(vp[j],vp[j+1]);
		if(t!=0)
			cout<<endl;
		for(int i=0;i<n;i++)
			cout<<vp[i].second<<","<<vp[i].first<<endl;
	}
	return 0;
}


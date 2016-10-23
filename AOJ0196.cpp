//AOJ0196
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#define PB push_back
#define MP make_pair
using namespace std;
int main(){
	while(1){
		int n;
		cin>>n;
		if(!n)
			break;
		vector<pair<pair<int,int>,int> > vpp; 
		for(int i=0;i<n;i++){
			char c,w=0,l=0;
			cin>>c;
			for(int i=0;i<n-1;i++){
				int a;
				cin>>a;
				if(a==0)
					w++;
				else if(a==1)
					l++;
			}
			vpp.PB(MP(MP(-w,l),c));
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n-1;j++)
				if(vpp[j].first>vpp[j+1].first)
					swap(vpp[j],vpp[j+1]);
		for(int i=0;i<n;i++)
			cout<<(char)vpp[i].second<<endl;
	}
	return 0;
}


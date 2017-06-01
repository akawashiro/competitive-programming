#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
typedef long long ll;
int cou[2000000];
int main(){
	int k,n;
	string str;
	cin>>k>>str;
	n=str.size();
	map<int,ll> ma;
	ma[0]++;
	for(int i=0;i<n;i++)
		if(str[i]=='1'){
			cou[i+1]=cou[i]+1;
			ma[cou[i+1]]++;
		}else{
			cou[i+1]=cou[i];
			ma[cou[i+1]]++;
		}
	ll ans=0;
	for(int i=0;i<=n;i++){
		ma[cou[i]]--;
		ans+=ma[cou[i]+k];
	}
	cout<<ans<<endl;
	return 0;
}

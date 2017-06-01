#include <iostream>
#include <limits.h>
typedef long long ll;
using namespace std;
ll k;
ll check(ll v){
	ll r=0,kk=1;
	while(0<v/kk){
		r+=v/kk;
		kk*=k;
	}
	return r;
}
int main(){
	ll n;
	cin>>n>>k;
	ll h=INT_MAX,l=0;
	while(1<h-l){
		ll m=(h+l)/2;
		if(n<=check(m))
			h=m;
		else
			l=m;
	}
	ll ans=(n<=check(h))?h:l;
	cout<<ans<<endl;
	return 0;
}


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
typedef long long LL;

LL nc[26];
LL fact(LL n){
     LL r=1;
     for(LL i=1;i<=n;i++)
	  r*=i;
     return r;
}

int main(){
     string s;
     cin>>s;
     for(int i=0;i<(int)s.size();i++)
	  nc[s[i]-'a']++;
     int odd=0;
     for(int i=0;i<26;i++)
	  if(nc[i]%2==1)
	       odd++;
     if(1<odd){
	  cout<<0<<endl;
	  return 0;
     }
     LL ans=fact((LL)s.size()/2);
     for(int i=0;i<26;i++)
	  ans/=fact((LL)nc[i]/2);
     cout<<ans<<endl;
     return 0;
}
     

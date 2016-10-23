#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
LL p[300000];
LL labs(LL l){if(l<0)return -l;else return l;}
int main(){
     int n;
     cin>>n;
     for(int i=0;i<n;i++)cin>>p[i];
     sort(p,p+n);
     LL ans=0;
     for(int i=0;i<n;i++)ans+=labs(i+1-p[i]);
     cout<<ans<<endl;
     return 0;
}

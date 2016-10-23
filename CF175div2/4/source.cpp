#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;

// int a[20],b[20],c[20];
// LL mod=1000000007;
// int main(){
//      int n;
//      for(n=1;n<=16;n++){
// 	  LL ans=0;
// 	  if(n%2==1){
// 	       for(int i=0;i<n;i++){a[i]=b[i]=i+1;}
// 	       do{
// 		    for(int i=0;i<n;i++)c[i]=(a[i]+b[i])%n+1;
// 		    sort(c,c+n);
// 		    if(unique(c,c+n)-c==n)ans++;
// 	       }while(next_permutation(b,b+n));
// 	       for(int i=1;i<=n;i++)ans=(ans*i)%mod;
// 	  }
//      }
//      return 0;
// }

int main(){
     int ans[]={0,1,0,18,0,1800,0,670320,0,734832000,0,890786230,0,695720788,0,150347555,0};
     int n;
     scanf("%d",&n);
     printf("%d\n",ans[n]);
     return 0;
}

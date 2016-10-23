#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;

int main(){
     LL n,k;
     cin>>n>>k;
     if(n==1){
	  cout<<0<<endl;
	  return 0;
     }
     if(n<=k){
	  cout<<1<<endl;
	  return 0;
     }
     LL u=k-1,d=0;
     for(int i=0;i<100;i++){
	  LL m=(u+d)/2;
	  LL a=(k-m)*(k+m-1)/2;
	  if(n-1<=a)
	       d=m;
	  else
	       u=m;
     }
     // cout<<"u="<<u<<" d="<<d<<endl;
     if(n-1<=(k-u)*(k+u-1)/2)
	  cout<<k-u<<endl;
     else if(n-1<=(k-d)*(k+d-1)/2)
	  cout<<k-d<<endl;
     else
	  cout<<-1<<endl;
     return 0;
}

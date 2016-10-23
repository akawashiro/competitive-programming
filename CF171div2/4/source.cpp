#include <stdio.h>
#include <cstring>
#include <algorithm>
#define INF 100
using namespace std;

int n;
int a[25];
int pre[25][25];
char memo[1<<23];
int best=INF;

int rec(int b){
     int k=n;
     while(!(b&(1<<(k-1))))k--;
     if(k==n){
	  int r=__builtin_popcount(b);
	  best=min(r,best);
	  return r;
     }else if(memo[b]!=-1)
	  return memo[b];
     else if(best<__builtin_popcount(b))
     	  return memo[b]=INF;
     else{
	  int r=INF;
	  int ok=false;
	  for(int i=0;i<n;i++){
	       if((b&(1<<i))&&(b&(1<<pre[i][k]))){
		   	 ok=true;
			 break;
	       }
	  }
	  if(ok){
	       for(int l=0;l<k;l++)
		    if(b&(1<<l))
			 r=min(r,rec((b&~(1<<l))|(1<<k)));
	       r=min(r,rec(b|(1<<k)));
	  }
	  return memo[b]=r;
     }
}

int main(){
     scanf("%d",&n);
     for(int i=0;i<n;i++)scanf("%d",a+i);
     memset(pre,-1,sizeof(pre));
     memset(memo,-1,sizeof(memo));
     for(int i=0;i<n;i++)
	  for(int j=0;j<n;j++)
	       for(int k=0;k<n;k++)
		    if(a[i]+a[k]==a[j])
			 pre[i][j]=k;
     int ans=rec(1);
     if(ans!=INF)printf("%d\n",ans);
     else printf("%d\n",-1);
     return 0;
}

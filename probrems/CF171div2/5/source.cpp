#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
string s;
int memo[1000000+1][2];
int rec(int k,int c){
     if(k==n)
	  return c;
     else if(memo[k][c]!=-1)
	  return memo[k][c];
     else{
	  int r;
	  if(c==0&&s[k]=='0')
	       r=rec(k+1,0);
	  else if(c==0&&s[k]=='1')
	       r=min(rec(k+1,1)+1,rec(k+1,0)+1);
	  else if(c==1&&s[k]=='0')
	       r=min(rec(k+1,1)+1,rec(k+1,0)+1);
	  else if(c==1&&s[k]=='1')
	       r=rec(k+1,1);
	  return memo[k][c]=r;
     }
}
int main(){
     cin>>s;
     n=s.size();
     reverse(s.begin(),s.end());
     memset(memo,-1,sizeof(memo));
     int ans=rec(0,0);
     printf("%d\n",ans);
     return 0;
}

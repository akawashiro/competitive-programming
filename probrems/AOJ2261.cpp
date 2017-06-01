#include <string.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;


int dp[32][32];

int ok(char a, char b){
  if( a=='(' ){
    return (b==')');
  }else if( a==')' ){
    return (b=='(');
  }else if( a=='{' ){
    return (b=='}');
  }else if( a=='}' ){
    return (b=='{');
  }else if( a=='[' ){
    return (b==']');
  }else if( a==']' ){
    return (b=='[');
  }else{
    return (a==b);
  }
}

int main(){
  string str;
  while(cin>>str){
    memset(dp,0,sizeof(dp));
    int p = str.find("iwi");
    string s1 = str.substr(0,p);
    string tmp = str.substr(p+3);
    string s2 = string(tmp.rbegin(), tmp.rend());

    int n = s1.length();
    int m = s2.length();

    for(int i=1;i<n+1;i++){
      for(int j=1;j<m+1;j++){
	dp[i][j] = max(dp[i-1][j-1]+ok(s1[i-1],s2[j-1]), max(dp[i-1][j], dp[i][j-1]));
      }
    }
    printf("%d\n",dp[n][m]*2 + 3);
  }
  return 0;
}

#include <stdio.h>
using namespace std;
int gcd(int x,int y){
  if(y==0)
    return x;
  else
    gcd(y,x%y);
}
int main(){
  int a,b;
  while(scanf("%d%d",&a,&b)!=EOF)
    printf("%d\n",gcd(a,b));
 return 0;
}
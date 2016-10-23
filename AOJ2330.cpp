//AOJ2330
#include <stdio.h>
typedef long long LL;
int f(LL n){
	if(n<2)	return 0;
	if(n%3==0)	return f(n/3)+1;
	if(0<n%3)	return f(n/3+1)+1;
}
int main(){
	LL n;
	scanf("%lld",&n);
	printf("%d\n",f(n));
}


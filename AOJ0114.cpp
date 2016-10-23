//AOJ0114
#include <stdio.h>
typedef long long LL;
LL gcd(LL x,LL y){
	if(y==0)return x;
	else	return gcd(y,x%y);
}
LL lcm(LL x,LL y){
	return x*y/gcd(x,y);
}
LL f(LL a,LL m){
	LL x=a%m,r=1;
	for(;x!=1;r++)
		x=a*x%m;
	return r;
}
int main(){
	while(1){
		LL a1,m1,a2,m2,a3,m3;
		scanf("%lld%lld%lld%lld%lld%lld",&a1,&m1,&a2,&m2,&a3,&m3);
		if(!a1&&!a2)	break;
		LL r1=f(a1,m1),r2=f(a2,m2),r3=f(a3,m3);
		printf("%lld\n",lcm(r1,lcm(r2,r3)));
	}
	return 0;
}


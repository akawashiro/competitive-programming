#include <stdio.h>
#include <map>
using namespace std;
typedef long long LL;
static const LL MOD=1000000007;
LL ADD(LL x,LL y){	return (x+y)%MOD;	}
LL SUB(LL x,LL y){	return (x-y+MOD)%MOD;	}
LL MUL(LL x,LL y){	return ((x*y)%MOD+MOD)%MOD;	}
LL POW(LL x,LL e)
{
	LL r=1;
	for(;e;x=MUL(x,x),e>>=1)
		if(e&1)
			r=MUL(r,x);
	return r;
}
LL DIV(LL x,LL y){	return MUL(x,POW(y,MOD-2));	}
LL COMB(LL n,LL k)
{
	LL r=1;
	for(LL i=1;i<=k;i++)
		r=DIV(MUL(r,n-i+1),i);
	return r;
}
int isLucky(int n){
	int r=1;
	while(0<n){
		if(n%10!=4&&n%10!=7)
			r=0;
		n/=10;
	}
	return r;
}
int main(){
	map<int,int> ma;
	int n,k,ln=0;
	LL m=0;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		if(isLucky(a)){
			if(ma.find(a)==ma.end()){
				ma[a]=ln;
				ln++;
				m++;
			}
		}else{
			m++;
		}
	}
	LL ans=1;
	for(LL i=1;i<=n;i++)
		ans*=i;
	return 0;
}


//LuckySubsequence
#include <stdio.h>
#include <map>
typedef long long LL;
using namespace std;
int isLucky(int n){
	while(0<n){
		if(n%10!=4&&n%10!=7)
			return 0;
		n/=10;
	}
	return 1;
}
static const LL MOD=1000000007;
LL ADD(LL x,LL y){	return (x+y)%MOD;	}
LL SUB(LL x,LL y){	return (x-y+MOD)%MOD;	}
LL MUL(LL x,LL y){	return ((x*y)%MOD+MOD)%MOD;	}
LL POW(LL x,LL e){
	LL r=1;
	for(;e;x=MUL(x,x),e>>=1)
		if(e&1)
			r=MUL(r,x);
	return r;
}
LL DIV(LL x,LL y){	return MUL(x,POW(y,MOD-2));	}
LL COMB(LL n,LL k){
	LL r=1;
	for(LL i=1;i<=k;i++)
		r=DIV(MUL(r,n-i+1),i);
	return r;
}
LL fact[100000+1];
int lucky[1<<10];
LL dp[1<<10][1<<10];
int main(){
	fact[0]=1;
	for(LL i=1;i<100000+1;i++)
		fact[i]=MUL(fact[i-1],i);
	int n,k,ln=0,m=0;
	scanf("%d%d",&n,&k);
	map<int,int> ma;
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		//printf("a=%d\n",a);
		if(isLucky(a)){
			//printf("%d is lucky\n",a);
			ma[a]++;
			m++;
		}
	}
	for(map<int,int>::iterator it=ma.begin();it!=ma.end();it++){
		lucky[ln]=(*it).second;
		//printf("lucky[%d]=%d(%d)\n",ln,lucky[ln],(*it).first);
		ln++;
	}
	dp[0][0]=1;
	for(int i=1;i<=ln;i++)
		for(int j=0;j<=ln;j++){
			dp[i][j]=dp[i-1][j];
			if(0<j)
				dp[i][j]+=dp[i-1][j-1]*lucky[i-1];
			dp[i][j]%=MOD;
		}
	LL ans=0;
	for(int i=ln;0<=i;i--){
		if(0<=n-m&&0<=k-i&&k-i<=n-m){
			//printf("dp[%d][%d]=%lld\n",ln,i,dp[ln][i]);
			//printf("COMB(%d,%d)=%lld\n",n-m,k-i,COMB(n-m,k-i));
			//ans+=dp[ln][i]*COMB(n-m,k-i);
			ans+=MUL(dp[ln][i],DIV(DIV(fact[n-m],fact[k-i]),fact[n-m-k+i]));
			ans%=MOD;
		}
	}
	printf("%lld\n",ans);
	return 0;
}


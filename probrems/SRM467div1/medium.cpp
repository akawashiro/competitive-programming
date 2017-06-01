typedef long long LL;

static const MOD=1000000007;
LL ADD(LL x,LL y){	return (x+y)%MOD;	}
LL SUB(LL x,LL Y){	return (x-y+MOD)%MOD;	}
LL MUL(LL x,LL y){	return ((x*y)%MOD+MOD)%MOD;	}
LL POW(LL x,LL e)
{
	LL r=1;
	for(;e;x=MUL(x,x);e>>=1)
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

class SuperSum
{
	public:
		int calculate(int k, int n) 
		{
			return (int)COMB(n+k,k+1);
		}
};


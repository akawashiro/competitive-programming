static const LL MOD = 1e9+7;
LL ADD(LL x,LL y){	return (x+y)%MOD;	}
LL SUB(LL x,LL y){	return (x-y+MOD)%MOD;	}
LL MUL(LL x,LL y){	return ((x*y)%MOD+MOD)%MOD;	}
LL POW(LL a, LL x) {
  LL res = 1;
  while(x > 0) {
  if(x & 1) res = res * a % MOD;
  a = a * a % MOD;
  x >>= 1;
  }
  return res;
}
LL DIV(LL x,LL y){
    return MUL(x,POW(y,MOD-2));
}
LL COMB(LL n, LL r) {
  LL res = 1;
  LL R = min(r,n-r);
  LL RR = R;
  for(LL i = n; i > n - R; i--) {
    res = res * (i % MOD)  % MOD;
    res = res * POW(RR,MOD-2) % MOD;
    RR--;
  }
  return res;
}



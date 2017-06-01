//AOJ2331
#include <stdio.h>
#define MAX_N 400000
int n;
int bit0[MAX_N],bit1[MAX_N];
int sum(int *b,int i){
	int s=0;
	while(0<i){
		s+=b[i];
		i-=i&-i;
	}
	return s;
}
void add(int *b,int i,int v){
	while(i<=n){
		b[i]+=v;
		i+=i&-i;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int r,l;
		scanf("%d%d",&l,&r);
		l--,r--;
		add(bit0,l,-l+1);
		add(bit0,r+1,r);
		add(bit1,l,1);
		add(bit1,r+1,-1);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int s=sum(bit0,i)+sum(bit1,i)*i-sum(bit0,i-1)-sum(bit1,i-1)*(i-1);
		if(i<=s)
			ans=i;
	}
	printf("%d\n",ans);
	return 0;
}


#include <stdio.h>
int main(){
	long long n,s=0;
	scanf("%lld",&n);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		s+=a;
	}
	printf("%lld\n",s/n);
	return 0;
}


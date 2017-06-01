//AOJ1109
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long LL;
int main(){
	while(1){
		LL z;
		scanf("%lld",&z);
		if(z==0)	break;
		z=z*z*z;
		LL ans=z;
		for(LL x=1;x*x*x<z;x++)
			for(LL y=x;x*x*x+y*y*y<z;y++)
				ans=min(ans,z-x*x*x-y*y*y);
		printf("%lld\n",ans);
	}
	return 0;
}


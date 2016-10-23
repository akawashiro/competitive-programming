//AOJ0148
#include <stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int a=(n%39==0)?39:n%39;
		printf("3C%02d\n",a);
	}
	return 0;
}

		

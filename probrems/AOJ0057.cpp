//AOJ0057
#include <stdio.h>
int main(){
	while(1){
		int n;
		if(scanf("%d",&n)==EOF)	break;
		int r=1;
		for(int i=0;i<n;i++)
			r+=i+1;
		printf("%d\n",r);
	}
	return 0;
}


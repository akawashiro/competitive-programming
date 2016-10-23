//AOJ0158
#include <stdio.h>
int main(){
	while(1){
		int n;
		scanf("%d",&n);
		if(!n)
			break;
		int i;
		for(i=0;n!=1;i++)
			if(n%2==0)
				n/=2;
			else
				n=n*3+1;
		printf("%d\n",i);
	}
	return 0;
}


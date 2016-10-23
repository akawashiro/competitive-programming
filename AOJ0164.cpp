//AOJ0164
#include <stdio.h>
int main(){
	while(1){
		int n;
		int ar[25];
		scanf("%d",&n);
		if(!n)
			break;
		for(int i=0;i<n;i++)
			scanf("%d",ar+i);
		int o=32;
		for(int t=0;0<o;t++){
			while(o%5!=1)
				o--;
			printf("%d\n",o);
			o-=ar[t%n];
			if(o<0)
				o=0;
			printf("%d\n",o);
		}
	}
	return 0;
}


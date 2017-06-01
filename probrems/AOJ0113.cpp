//AOJ0113
#include <stdio.h>
int a[100],b[100];
int main(){
	int p,q;
	while(scanf("%d%d",&p,&q)!=EOF){
		p%=q;
		p*=10;
		if(p==0){
			printf("0\n");
			continue;
		}
		for(int i=0;;i++){
			if(p==0){
				for(int j=0;j<i;j++)
					printf("%d",a[j]);
				printf("\n");
				break;
			}
			int e=0;
			for(int j=0;j<i;j++)
				if(p==b[j]){
					for(int k=0;k<i;k++)
						printf("%d",a[k]);
					printf("\n");
					for(int k=0;k<i;k++)
						printf("%c",(k<j)?' ':'^');
					printf("\n");
					e=1;
				}
			if(e)
				break;
			a[i]=p/q;
			b[i]=p;
			p%=q;
			p*=10;
		}
	}
	return 0;
}


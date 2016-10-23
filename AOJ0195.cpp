//AOJ0195
#include <stdio.h>
int main(){
	while(1){
		int s,v=-1;
		for(int i=0;i<5;i++){
			int a,b;
			if(scanf("%d%d",&a,&b)==EOF)
				return 0;
			if(v<a+b){
				v=a+b;
				s='A'+i;
			}
		}
		printf("%c %d\n",s,v);
	}
	return 0;
}


//AOJ0054
#include <stdio.h>
int main(){
	while(1){
		int a,b,n;
		if(scanf("%d%d%d",&a,&b,&n)==EOF)	break;
		a=a%b;
		int s=0;
		for(int i=0;i<n;i++){
			a*=10;
			s+=a/b;
			a%=b;
		}
		printf("%d\n",s);
	}
	return 0;
}


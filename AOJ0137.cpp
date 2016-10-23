#include <stdio.h>
int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		printf("Case %d:\n",t);
		int x;
		scanf("%d",&x);
		for(int i=0;i<10;i++){
			x=x*x%1000000/100;
			printf("%d\n",x);
		}
	}
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
int main(){
	printf("%d %d\n",5000,500000);
	for(int i=0;i<500000;i++){
		int j=i%5000+1;
		printf("%d %d %d\n",j,j,5000-j);
	}
	return 0;
}


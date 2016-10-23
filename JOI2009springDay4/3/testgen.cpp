#include <stdio.h>

int main()
{
	for(int i=1;i<=32;i++){
		printf("time ./execution.out < Starry_Sky/%02d.in > %02dout\n",i,i);
		printf("diff %02dout Starry_Sky/%02d.out\n",i,i);
	}
}


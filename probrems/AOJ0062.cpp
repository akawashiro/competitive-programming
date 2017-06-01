#include <stdio.h>
int main()
{
	char a[20],b[20];
	while(1){
		if(scanf("%s",b)==EOF)
			break;
		for(int i=0;i<10;i++)
			b[i]-='0';
		for(int i=0;i<9;i++){
			for(int j=0;j<10;j++)
				a[j]=b[j];
			for(int j=0;j<9;j++)
				b[j]=(a[j]+a[j+1])%10;
		}
		printf("%d\n",b[0]);
	}
	return 0;
}


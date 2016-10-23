//AOJ0184
#include <stdio.h>
#include <string.h>
int ar[7];
int main(){
	while(1){
		int n;
		scanf("%d",&n);
		if(!n)
			break;
		memset(ar,0,sizeof(ar));
		for(int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			if(a<10)	ar[0]++;
			else if(a<20)	ar[1]++;
			else if(a<30)	ar[2]++;
			else if(a<40)	ar[3]++;
			else if(a<50)	ar[4]++;
			else if(a<60)	ar[5]++;
			else	ar[6]++;
		}
		for(int i=0;i<7;i++)
			printf("%d\n",ar[i]);
	}
	return 0;
}


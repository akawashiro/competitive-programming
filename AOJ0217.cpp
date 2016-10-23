//AOJ0217
#include <stdio.h>
int main()
{
	while(1){
		int n;
		scanf("%d",&n);
		if(!n)
			break;
		int p=0,d=-1;
		for(int i=0;i<n;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if(d<b+c)
				p=a,d=b+c;
		}
		printf("%d %d\n",p,d);
	}
	return 0;
}


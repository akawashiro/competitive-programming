//AOJ0030
#include <stdio.h>

int popCount(int _mask)
{
	int r=0;
	for(int i=0;i<31;i++)
		if(_mask & (1<<i))
			r++;
	return r;
}

int main()
{
	while(1){
		int n,s;
		scanf("%d%d",&n,&s);
		if(!n&&!s)
			break;
		int r=0;
		for(int m=0;m<1<<10;m++)
			if(popCount(m)==n){
				int t=0;
				for(int i=0;i<10;i++)
					if(m&(1<<i))
						t+=i;
				if(s==t)
					r++;
			}
		printf("%d\n",r);
	}
	return 0;
}


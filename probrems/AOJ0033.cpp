//AOJ0033
#include <stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	for(;0<T;T--){
		int a[10];
		for(int i=0;i<10;i++)
			scanf("%d",a+i);
		int r=0;
		for(int m=0;m<1<<10;m++){
			int s=-1,t=1;
			for(int i=0;i<10;i++)
				if(m&(1<<i)){
					if(s>a[i])
						t=0;
					s=a[i];
				}
			s=-1;
			for(int i=0;i<10;i++)
				if(!(m&(1<<i))){
					if(s>a[i])
						t=0;
					s=a[i];
				}
			if(t)
				r=1;
		}
		if(r)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}


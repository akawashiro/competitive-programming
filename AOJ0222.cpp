#include <stdio.h>
int p[10000000+1];
int main()
{
	for(int i=0;i<10000000+1;i++)
		p[i]=1;
	p[0]=0,p[1]=0;
	for(int i=0;i<10000000+1;i++)
		if(p[i])
			for(int j=i+i;j<10000000+1;j+=i)
				p[j]=0;
	while(1){
		int n;
		scanf("%d",&n);
		if(!n)
			break;
		int i;
		for(i=n;;i--)
			if(p[i]+p[i-2]+p[i-6]+p[i-8]==4)
				break;
		printf("%d\n",i);
	}
	return 0;
}


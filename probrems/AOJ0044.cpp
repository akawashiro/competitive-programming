#include <cstdio>
#include <cstring>

bool isPrime[100000];

int main()
{
	for(int i=0;i<100000;i++)
		isPrime[i]=true;

	isPrime[0]=isPrime[1]=false;

	for(int i=0;i<100000;i++)
		if(isPrime[i])
			for(int j=i+i;j<100000;j+=i)
				isPrime[j]=false;

	int input;
	while(scanf("%d",&input)==1)
	{
		for(int i=input-1;0<i;i--)
			if(isPrime[i])
			{
				printf("%d ",i);
				break;
			}
		for(int i=input+1;i<100000;i++)
			if(isPrime[i])
			{
				printf("%d\n",i);
				break;
			}
	}

	return 0;
}


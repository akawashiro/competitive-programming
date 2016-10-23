#include <stdio.h>

class PrimeContainers{
	public:
		int containerSize(int N)
		{
			bool isPrime[N+1];
			for(int i=0;i<N+1;i++)
				isPrime[i]=true;
			isPrime[0]=false;
			isPrime[1]=false;
			for(int i=0;i<N+1;i++){
				if(isPrime[i]){
					for(int j=i;j<N+1;j+=i)
						isPrime[j]=false;
					isPrime[i]=true;
				}
			}

			/*for(int i=0;i<N+1;i++)
				if(isPrime[i])
				printf("%d is prime\n",i);*/

			int count=0;
			for(int i=1;0<N/i;i*=2)
				if(isPrime[N/i])
					count++;

			return count;
		}
};

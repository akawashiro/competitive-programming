#include <stdio.h>

class BaseConfusion{
		public:
				long long sum(int M,int N,int B);
};

long long s(int N,int B)
{
		N++;
		long long r=0;
		for(long long b0=B,b1=1;b0/B<=N;b0*=B,b1*=B+1){
				//printf("b0=%lld,b1=%lld \n",b0,b1);
				r+=N/b0*b0*(B-1)/2*b1;
				long long n=N%b0;
				for(long long i=0;0<n;i++){
						if(n<b0/B)
								r+=i*n*b1;
						else
								r+=i*b0/B*b1;
						n-=b0/B;
				}
		}
		return r;
}

long long BaseConfusion::sum(int M,int N,int B)
{
		//printf("%lld\n",s(N,B));
		//printf("%lld\n",s(M-1,B));
		return s(N,B)-s(M-1,B);
}

/*int main()
{
		BaseConfusion b;
		printf("%lld\n",b.sum(1,8,3));
}*/

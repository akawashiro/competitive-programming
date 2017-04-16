#define MAX_N
for(int i=0;i<MAX_N;i++)	prime[i]=1;
prime[0]=prime[1]=0;
	for(int i=0;i<MAX_N;i++)
if(prime[i])
	for(int j=i+i;j<MAX_N;j+=i)
	prime[j]=0;

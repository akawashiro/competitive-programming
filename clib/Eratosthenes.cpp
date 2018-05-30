#define MAX_N 10000
int prime[MAX_N];

void eras(){
    for(int i=0;i<MAX_N;i++)
        prime[i]=1;
    prime[0]=prime[1]=0;
    for(int i=0;i<MAX_N;i++)
        if(prime[i])
            for(int j=i+i;j<MAX_N;j+=i)
                prime[j]=0;
}

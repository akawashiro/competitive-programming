#include <stdio.h>

int p[3000000];
int main(){
     int n;
     scanf("%d",&n);
     for(int i=1;i<=n;i++)
	  p[i]=i;
     for(int start=1;start<n;start++){
	  int k=start+1;
	  if(n%k!=0)
	       p[start+n]=p[start+n/k*k];
	  // for(int i=n-1;n/k*k<=i;i--)
	  //      p[start+i+1]=p[start+i];
	  for(int i=n/k*k;0<=i;i-=k)
	       p[start+i+k]=p[start+i];
	  // printf("start=%d\n",start);
	  // for(int i=start+1;i<start+1+n;i++)
	  //      printf("%d ",p[i]);
	  // printf("\n");
     }
     for(int i=n;i<2*n;i++)
	  printf("%d ",p[i]);
     printf("\n");
     return 0;
}

	       

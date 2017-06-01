#include <stdio.h>
#include <algorithm>
using namespace std;

int a[100000];
int main(){
     int n,k;
     scanf("%d%d",&n,&k);
     for(int i=0;i<n;i++)a[i]=i+1;
     reverse(a,a+k+1);
     for(int i=0;i<n;i++)printf("%d ",a[i]);
     printf("\n");
     return 0;
}

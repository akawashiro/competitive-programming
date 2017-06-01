#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

int a[100000];
int main(){
     int n,t;
     scanf("%d%d",&n,&t);
     for(int i=0;i<n;i++)
	  scanf("%d",a+i);
     int ans=0,sum=0;
     queue<int> qu;
     for(int i=0;i<n;i++){
	  qu.push(i);sum+=a[i];
	  if(t<sum){sum-=a[qu.front()];qu.pop();}
	  ans=max((int)qu.size(),ans);
     }
     printf("%d\n",ans);
     return 0;
}

     

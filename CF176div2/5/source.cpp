#include <stdio.h>
#include <stack>
#define MAX_N 1000000
using namespace std;
int p[MAX_N];
int main(){
     int n,m;
     scanf("%d",&n);
     for(int i=0;i<n;i++)scanf("%d",p+i);
     scanf("%d",&m);
     for(int i=0;i<m;i++){int a;scanf("%d",&a);p[a-1]*=-1;}
     stack<int> st;
     // for(int i=0;i<n;i++)
     // 	  printf("%d ",p[i]);
     // printf("--debug\n");
     for(int i=n-1;0<=i;i--){
	  if(p[i]<0)st.push(p[i]);
	  else if(st.empty()||st.top()+p[i]!=0){
	       p[i]*=-1;
	       st.push(p[i]);
	  }else{
	       st.pop();
	  }
	  // for(int i=0;i<n;i++)
	  //      printf("%d ",p[i]);
	  // printf("--debug\n");
     }
     if(!st.empty()){
	  printf("NO\n");
     }else{
	  printf("YES\n");
	  for(int i=0;i<n;i++)
	       printf("%d ",p[i]);
	  printf("\n");
     }
     return 0;
}

	  

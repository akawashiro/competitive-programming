#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int a[100000],ix[100000],l[100000],r[100000];
vector<int> ng;

int main(){
     int n,m;
     scanf("%d%d",&n,&m);
     for(int i=0;i<n;i++)scanf("%d",a+i);
     for(int i=0;i<m;i++){scanf("%d%d",l+i,r+i);l[i]--;r[i]--;}
     ix[0]=0;
     for(int i=1;i<n;i++){if(a[i-1]==a[i])ix[i]=ix[i-1];else ix[i]=ix[i-1]+1;}
     for(int i=0;i<m;i++){l[i]=ix[l[i]];r[i]=ix[r[i]];}
     // printf("ix  ");
     // for(int i=0;i<n;i++)
     // 	  printf("%d ",ix[i]);
     // printf("\n");
     n=unique(a,a+n)-a;
     for(int i=1;i<n-1;i++){if(a[i-1]>a[i]&&a[i]<a[i+1])ng.push_back(i);}
     for(int i=0;i<m;i++){
	  if(lower_bound(ng.begin(),ng.end(),l[i]+1)==ng.end())
	       printf("Yes\n");
	  else{
	       int b=*lower_bound(ng.begin(),ng.end(),l[i]+1);
	       // printf("b=%d\n",b);
	       if(b<r[i])printf("No\n");
	       else printf("Yes\n");
	  }
     }
     
     // printf("a   ");
     // for(int i=0;i<n;i++)
     // 	  printf("%d ",a[i]);
     // printf("\n");
     // printf("ng  ");
     // for(int i=0;i<(int)ng.size();i++)
     // 	  printf("%d ",ng[i]);
     // printf("\n");
     
     // for(int i=0;i<m;i++)
     // 	  printf("l=%d r=%d\n",l[i],r[i]);
     // printf("\n");

     return 0;
}

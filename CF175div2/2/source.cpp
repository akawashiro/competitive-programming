#include <stdio.h>
int p[100000+1];
int main(){
     int n,s,t;
     scanf("%d%d%d",&n,&s,&t);
     for(int i=1;i<=n;i++)scanf("%d",p+i);
     int ans;
     for(ans=0;ans<2*n;ans++){
	  if(s==t)break;
	  s=p[s];
     }
     if(ans!=2*n)printf("%d\n",ans);
     else printf("-1\n");
     return 0;
}

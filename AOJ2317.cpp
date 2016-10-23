//AOJ2317
#include <stdio.h>
#include <algorithm>
using namespace std;
long long s[100000],t[100000],p[100010],P[100010];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%lld%lld",s+i,t+i);
	for(int i=0;i<m;i++)
		scanf("%lld",p+i);
	p[m]=0,p[m+1]=1000000000+1;
	m+=2;
	sort(p,p+m);
	P[0]=p[0];
	for(int i=1;i<m;i++)
		P[i]=p[i]-P[i-1];
	//for(int i=0;i<m;i++)
	//printf("P[%d]=%d\n",i,P[i]);
	long long ans=0;
	for(int i=0;i<n;i++){
		if(max(s[i],t[i])<p[0]||p[m-1]<min(s[i],t[i])){
			ans+=max(s[i],t[i])-min(s[i],t[i]);
		}else if(s[i]<t[i]){
			//printf("s[i]<t[i]\n");
			int a=lower_bound(p,p+m,s[i])-p;
			int b=(upper_bound(p,p+m,t[i])-p)-1;
			//printf("a=%d b=%d\n",a,b);
			if(a%2!=b%2){
				//printf("t[%d]=%d s[%d]=%d P[%d]=%d P[%d]=%d\n",i,t[i],i,s[i],b,P[b],a-1,P[a-1]);
				ans+=t[i]-s[i]-P[b]+P[a-1];
			}else{
				ans+=-s[i]-P[b+1]+P[a-1]+p[b+1];
			}
		}else{
			//printf("s[i]>t[i]\n");
			int a=lower_bound(p,p+m,t[i])-p;
			int b=(upper_bound(p,p+m,s[i])-p)-1;
			//printf("a=%d b=%d\n",a,b);
			if(a%2!=b%2)
				ans+=s[i]-t[i]-P[b]+P[a-1];
			else{
				ans+=s[i]-P[b]+P[a]-p[a];
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}


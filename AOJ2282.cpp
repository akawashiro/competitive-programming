//AOJ2282
#include <stdio.h>
int a[1000];
int main(){
	while(1){
		int n,m;
		scanf("%d%d",&n,&m);
		if(!n&&!m)	break;
		for(int i=0;i<n;i++)	scanf("%d",a+i);
		int r,t,d,c;
		r=0,t=m/a[0]*a[0],d=a[0],c=1;
		for(int i=1;i<n;i++){
			int tt=m/a[i]*a[i];
			if(tt==t){
				if(d==a[i])
					c++;
				else if(a[i]<d){
					r=i;
					c=1;
					d=a[i];
				}
			}else if(tt<t){
				r=i;
				t=tt;
				d=a[i];
				c=1;
			}
		}
		if(1<c)
			printf("%d\n",n);
		else
			printf("%d\n",r+1);
	}
	return 0;
}


//AOJ1153
#include <stdio.h>
int t[100],h[100];
int main(){
	while(1){
		int n,m,T=0,H=0,s=100000,tt,hh;
		scanf("%d%d",&n,&m);
		if(!n)	break;
		for(int i=0;i<n;i++){	scanf("%d",t+i);T+=t[i];	}
		for(int i=0;i<m;i++){	scanf("%d",h+i);H+=h[i];	}
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(T-H==(t[i]-h[j])*2&&t[i]+h[j]<s){
					s=t[i]+h[j];
					tt=t[i];
					hh=h[j];
				}
		if(s==100000){
			printf("-1\n");
		}else{
			printf("%d %d\n",tt,hh);
		}
	}
	return 0;
}


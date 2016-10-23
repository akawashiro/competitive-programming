//AOJ1048
#include <stdio.h>
#include <string.h>
short use[10010][1300];
int main(){
	while(1){
		int n,m,r,q;
		memset(use,0,sizeof(use));
		scanf("%d%d",&n,&m);
		if(n==0&&m==0)	break;
		scanf("%d",&r);
		for(int i=0;i<r;i++){
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			if(d==1)	use[c][a]++;
			else		use[c][a]--;
		}
		for(int i=0;i<=m;i++){
			int a=0;
			for(int j=0;j<1300;j++){
				a+=use[i][j];
				use[i][j]=a;
			}
		}
		scanf("%d",&q);
		for(int i=0;i<q;i++){
			int a,b,c,d=0;
			scanf("%d%d%d",&a,&b,&c);
			for(int j=a;j<b;j++)
				if(0<use[c][j])
					d++;
			printf("%d\n",d);
		}
	}
	return 0;
}


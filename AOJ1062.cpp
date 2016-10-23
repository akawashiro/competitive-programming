//AOJ1062
#include <stdio.h>
int main(){
	while(1){
		int n;
		int l=0,ll=0,d=0,dd=0,m=0,mm=0;
		scanf("%d",&n);
		if(!n)	break;
		int a,b,c;
		for(int i=0;i<n;i++){
			scanf("%d%*c%d%d",&a,&b,&c);
			int t=(0<c-b)?c-b:60+c-b;
			if(11<=a&&a<15)			l++,ll+=(t<=8);
			else if(18<=a&&a<21)	d++,dd+=(t<=8);
			else if(21<=a||a<2)		m++,mm+=(t<=8);
		}
		printf("lunch ");
		if(0<l)	printf("%d\n",ll*100/l);
		else	printf("no guest\n");
		printf("dinner ");
		if(0<d)	printf("%d\n",dd*100/d);
		else	printf("no guest\n");
		printf("midnight ");
		if(0<m)	printf("%d\n",mm*100/m);
		else	printf("no guest\n");
	}
	return 0;
}


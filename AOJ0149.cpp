//AOJ0149
#include <stdio.h>
int l[4],r[4];
int main(){
	double d,e;
	while(scanf("%lf%lf",&d,&e)!=EOF){
		if(1.1<=d)	l[0]++;
		else if(0.6<=d)	l[1]++;
		else if(0.2<=d)	l[2]++;
		else	l[3]++;
		if(1.1<=e)	r[0]++;
		else if(0.6<=e)	r[1]++;
		else if(0.2<=e)	r[2]++;
		else	r[3]++;
	}
	for(int i=0;i<4;i++)
		printf("%d %d\n",l[i],r[i]);
	return 0;
}


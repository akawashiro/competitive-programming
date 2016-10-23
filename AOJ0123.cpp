//AOJ0123
#include <stdio.h>
int max(int a,int b){	return (a>b)?a:b; }
int j500(double d){
	if(d<35.5)		return 0;
	else if(d<37.5)	return 1;
	else if(d<40)	return 2;
	else if(d<43)	return 3;
	else if(d<50)	return 4;
	else if(d<55)	return 5;
	else if(d<70)	return 6;
	else			return 7;
}
int j1000(double d){
	if(d<71)		return 0;
	else if(d<77)	return 1;
	else if(d<83)	return 2;
	else if(d<89)	return 3;
	else if(d<105)	return 4;
	else if(d<116)	return 5;
	else if(d<148)	return 6;
	else			return 7;
}
int main(){
	double d,e;
	while(scanf("%lf%lf",&d,&e)!=EOF){
		int r=max(j500(d),j1000(e));
		if(r==0)	printf("AAA\n");
		else if(r==1)	printf("AA\n");
		else if(r==2)	printf("A\n");
		else if(r==3)	printf("B\n");
		else if(r==4)	printf("C\n");
		else if(r==5)	printf("D\n");
		else if(r==6)	printf("E\n");
		else if(r==7)	printf("NA\n");
	}
	return 0;
}


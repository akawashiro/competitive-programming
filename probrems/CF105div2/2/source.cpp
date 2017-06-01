#include <stdio.h>
int main(){
	double vp,vd,t,f,c;
	scanf("%lf%lf%lf%lf%lf",&vp,&vd,&t,&f,&c);
	if(vp+0.0001>vd){printf("0\n");return 0;}
	int ans=0;
	double pp=vp*t;
	while(1){
		pp=pp*vd/(vd-vp);
		//printf("pp=%lf c=%lf\n",pp,c);
		if(c-0.0001<pp)	break;
		ans++;
		pp+=(f+pp/vd)*vp;
	}
	printf("%d\n",ans);
	return 0;
}


//AOJ1119
#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	for(;0<n;n--){
		int x=0,y=0,u=0,v=0,d=0,xd,yd;
		while(1){
			scanf("%d%d",&xd,&yd);
			if(xd==0&&yd==0)	break;
			x+=xd,y+=yd;
			if(d<x*x+y*y||(d==x*x+y*y&&u<x))
				u=x,v=y,d=x*x+y*y;
		}
		printf("%d %d\n",u,v);
	}
	return 0;
}


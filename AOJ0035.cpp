#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef long long LL;

double cross(double x1,double y1,double x2,double y2,double x3,double y3){
	double a1=x2-x1;
	double b1=y2-y1;
	double a2=x3-x1;
	double b2=y3-y1;
	//printf("r = %lf \n",a1*b2-a2*b1);
	return a1*b2-a2*b1;
}

int main(){
	double x1,y1,x2,y2,x3,y3,x4,y4;
	//printf("line = %d\n", __LINE__);
	while(scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)!=EOF){
		if((cross(x1,y1,x4,y4,x2,y2)>0&&cross(x2,y2,x1,y1,x3,y3)>0&&
				cross(x3,y3,x2,y2,x4,y4)>0&&cross(x4,y4,x3,y3,x1,y1)>0)||
				(cross(x1,y1,x4,y4,x2,y2)<0&&cross(x2,y2,x1,y1,x3,y3)<0&&
				 cross(x3,y3,x2,y2,x4,y4)<0&&cross(x4,y4,x3,y3,x1,y1)<0))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}



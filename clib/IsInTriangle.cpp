double cross(double x1,double y1,double x2,double y2,double x3,double y3){
	double a1=x2-x1;
	double b1=y2-y1;
	double a2=x3-x1;
	double b2=y3-y1;
	return a1*b2-a2*b1;
}
int isInTriangle(double x1,double y1,double x2,double y2,double x3,double y3,double xp,double yp){
	double c1=cross(xp,yp,x1,y1,x2,y2);
	double c2=cross(xp,yp,x2,y2,x3,y3);
	double c3=cross(xp,yp,x3,y3,x1,y1);
	return ((0<c1&&0<c2&&0<c3)||(c1<0&&c2<0&&c3<0));
}


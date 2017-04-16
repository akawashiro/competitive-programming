double heron(double x1,double y1,double x2,double y2,double x3,double y3){
	double a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	double b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	double c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	double s=(a+b+c)/2;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

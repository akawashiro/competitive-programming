double cross(double x1,double y1,double x2,double y2,double x3,double y3){
    double a1=x2-x1;
    double b1=y2-y1;
    double a2=x3-x1;
    double b2=y3-y1;
    return a1*b2-a2*b1;
}

#define MAX_D 16*1000000
#define INF 2147483647
int h,w;
int dat[MAX_D];
void initX(int O,int X1,int X2,int x,int k,int x1,int x2){
	if(x2<=X1||X2<=x1)	return;
	dat[O+k]=min(dat[O+k],x);
	if(1<x2-x1){
		initX(O,X1,X2,x,2*k+1,x1,(x1+x2)/2);
		initX(O,X1,X2,x,2*k+2,(x1+x2)/2,x2);
	}
}
void initY(int Y1,int Y2,int X1,int X2,int x,int k,int y1,int y2){
	if(y2<=Y1||Y2<=y1)	return;
	initX(k*4*w,X1,X2,x,0,0,w);
	if(1<y2-y1){
		initY(Y1,Y2,X1,X2,x,2*k+1,y1,(y1+y2)/2);
		initY(Y1,Y2,X1,X2,x,2*k+2,(y1+y2)/2,y2);
	}
}
int minX(int O,int X1,int X2,int k,int x1,int x2){
	if(x2<=X1||X2<=x1)	return INF;
	if(X1<=x1&&x2<=X2)	return dat[O+k];
	else if(1<x2-x1)	return min(minX(O,X1,X2,2*k+1,x1,(x1+x2)/2),
			minX(O,X1,X2,2*k+2,(x1+x2)/2,x2));
	else return INF;
}
int minY(int Y1,int Y2,int X1,int X2,int k,int y1,int y2){
	if(y2<=Y1||Y2<=y1)	return INF;
	if(Y1<=y1&&y2<=Y2)	return minX(k*4*w,X1,X2,0,0,w);
	else if(1<y2-y1)	return	min(minY(Y1,Y2,X1,X2,2*k+1,y1,(y1+y2)/2),
			minY(Y1,Y2,X1,X2,2*k+2,(y1+y2)/2,y2));
	else return INF;
}


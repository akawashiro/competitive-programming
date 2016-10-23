//CF103Meeting
#include <set>
#include <math.h>
#include <map>
#include <stdio.h>
using namespace std;
int main(){
	int xa,ya,xb,yb,n;
	scanf("%d%d%d%d%d",&xa,&ya,&xb,&yb,&n);
	if(xa>xb)	swap(xa,xb);
	if(ya>yb)	swap(ya,yb);
	set<pair<int,int> > se;
	for(int k=0;k<n;k++){
		int x,y,r,xd,yd;
		scanf("%d%d%d",&x,&y,&r);
		//printf("x=%d y=%d r=%d\n",x,y,r);
		xd=xa-x;
		if(xd*xd<=r*r){
			yd=sqrt(r*r-xd*xd);
			for(int i=max(ya,y-yd-1);i<=min(yb,y+yd+1);i++)
				if(xd*xd+(y-i)*(y-i)<=r*r)
					se.insert(make_pair(xa,i));
		}
		xd=xb-x;
		if(xd*xd<=r*r){
			yd=sqrt(r*r-xd*xd);
			for(int i=max(ya,y-yd-1);i<=min(yb,y+yd+1);i++)
				if(xd*xd+(y-i)*(y-i)<=r*r)
					se.insert(make_pair(xb,i));
		}
		yd=ya-y;
		if(yd*yd<=r*r){
			xd=sqrt(r*r-yd*yd);
			for(int i=max(xa,x-xd-1);i<=min(xb,x+xd+1);i++)
				if(yd*yd+(x-i)*(x-i)<=r*r)
					se.insert(make_pair(i,ya));
		}
		yd=yb-y;
		if(yd*yd<=r*r){
			xd=sqrt(r*r-yd*yd);
			for(int i=max(xa,x-xd-1);i<=min(xb,x+xd+1);i++)
				if(yd*yd+(x-i)*(x-i)<=r*r)
					se.insert(make_pair(i,yb));
		}
	}
	/*for(set<pair<int,int> >::iterator it=se.begin();it!=se.end();it++)
		printf("%d %d \n",(*it).first,(*it).second);*/
	printf("%d\n",(yb-ya)*2+(xb-xa)*2-se.size());
	return 0;
}



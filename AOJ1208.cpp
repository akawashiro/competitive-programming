//AOJ1208
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int gcd(int x,int y){
	if(y==0)	return x;
	else	return gcd(y,x%y);
}
int lcm(int x,int y){
	return x*y/gcd(x,y);
}
int main(){
	while(1){
		int p,n;
		scanf("%d%d",&p,&n);
		if(!p&&!n)	break;
		int x,y,u,v;
		double ud=100000,dd=1000000;
		for(int i=1;i<=n;i++){
			int a=(double)i*sqrt(p);
			for(int j=a-2;j<=a+2;j++){
				int m=i/gcd(i,j),c=j/gcd(i,j);
				if(n<c)	continue;
				double d=(double)c/m;
				if(d<sqrt(p)){
					if(sqrt(p)-d<dd){
						dd=sqrt(p)-d;
						u=c,v=m;
					}
				}else{
					if(d-sqrt(p)<ud){
						ud=d-sqrt(p);
						x=c,y=m;
					}
				}
			}
		}
		printf("%d/%d %d/%d\n",x,y,u,v);
	}
	return 0;
}


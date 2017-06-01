#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int h,w;
	scanf("%d%d",&h,&w);
	if(w<h)	
		swap(w,h);
	if(h==1){	
		printf("%d\n",w);	
	}else if(h==2){
		int r=0;
		while(0<w){
			if(w<2)
				r+=w*h;
			else
				r+=2*h;
			w-=4;
		}
		printf("%d\n",r);
	}else{
		printf("%d\n",(h*w+1)/2);
	}
	return 0;
}


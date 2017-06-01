//AOJ0160
#include <stdio.h>
int main(){
	while(1){
		int n;
		int ans=0;
		scanf("%d",&n);
		if(!n)
			break;
		for(int i=0;i<n;i++){
			int x,y,h,w;
			scanf("%d%d%d%d",&x,&y,&h,&w);
			int a,b;
			if(x+y+h<=60)				a=600;
			else if(x+y+h<=80)	a=800;
			else if(x+y+h<=100)	a=1000;
			else if(x+y+h<=120)	a=1200;
			else if(x+y+h<=140)	a=1400;
			else if(x+y+h<=160)	a=1600;
			else								a=0;
			if(w<=2)						b=600;
			else if(w<=5)				b=800;
			else if(w<=10)			b=1000;
			else if(w<=15)			b=1200;
			else if(w<=20)			b=1400;
			else if(w<=25)			b=1600;
			else								b=0;
			if(a==0||b==0)
				a=b=0;
			if(a<b)
				ans+=b;
			else
				ans+=a;
		}
		printf("%d\n",ans);
	}
	return 0;
}


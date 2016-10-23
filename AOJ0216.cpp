#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	while(1){
		int a,r=1150;
		scanf("%d",&a);
		if(a==-1)
			break;
		a=max(0,a-10);
		for(int i=0;i<3;i++){
			int b,c;
			if(a<10||i==2)
				b=a;
			else
				b=10;
			if(i==0)	 c=125;
			else if(i==1)c=140;
			else if(i==2)c=160;
			r+=b*c;
			a=max(0,a-10);
		}
		printf("%d\n",4280-r);
	}
	return 0;
}


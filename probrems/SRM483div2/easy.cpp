#include <stdio.h>

class DigitHoles{
		public:
				int numHoles(int number);
};

int DigitHoles::numHoles(int number)
{
		char c[100];
		int r=0;
		sprintf(c,"%d",number);
		int i=0;
		while(c[i]!=NULL){
				if(c[i]=='0' || c[i]=='4' || c[i]=='6' || c[i]=='9'){
						r++;
				}else if(c[i]=='8'){
						r+=2;
				}
				i++;
		}
		return r;
}


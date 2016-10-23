#include <stdio.h>

class RabbitNumber{
		public:
				int theCount(int low, int high);
};

int RabbitNumber::theCount(int low, int high)
{
		int count=0;
		for(int i=low;i<=high;i++){
				char s[100];
				sprintf(s,"%d",i);
				int j=0;
				bool flag=true;
				while(s[j]!=NULL){
						if(!('0'<=s[j] && s[j]<='3')){
								flag=false;
								break;
						}
				}
				if(flag)
						count++;
		}
		return count;
}

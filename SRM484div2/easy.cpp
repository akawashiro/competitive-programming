#include <iostream>
#include <string>
using namespace std;

class NumberMagicEasy{
		public:
				int theNumber(string answer);
};

int NumberMagicEasy::theNumber(string answer)
{
		bool isexist[17];
		for(int i=0;i<17;i++)
				isexist[i]=true;
		isexist[0]=false;
		if(answer[0]=='N'){
				for(int i=1;i<9;i++)
						isexist[i]=false;
		}
		if(answer[1]=='N'){
				for(int i=1;i<5;i++)
						isexist[i]=false;
				for(int i=9;i<12;i++)
						isexist[i]=false;
		}
		if(answer[2]=='N'){
				isexist[1]=false;	isexist[2]=false;
				isexist[5]=false;	isexist[6]=false;
				isexist[9]=false;	isexist[10]=false;
				isexist[13]=false;	isexist[13]=false;
		}
		if(answer[3]=='N'){
				for(int i=1;i<17;i++){
						if(i%2 == 1)
								isexist[i]=false;
				}
		}
		for(int i=1;i<17;i++)
				if(isexist[i]==true)
						return i;
		return -1;
}


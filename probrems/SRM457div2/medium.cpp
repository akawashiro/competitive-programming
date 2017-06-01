#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
using namespace std;

class TheTriangleBothDivs{
	public:
		string fix(string time)
		{
			int minute=0;
			int hour=1000;
			minute+=(time[3]=='?') ? 0 : (time[3]-'0')*10;
			minute+=(time[4]=='?') ? 0 : time[4]-'0';

			for(int h1=0;h1<=2;h1++){
				if(time[0]!='?' && h1!=time[0]-'0')
					continue;
				for(int h2=0;h2<10;h2++){
					if(time[1]!='?' && h2!=time[1]-'0')
						continue;
					if(23 < h1*10+h2)
						continue;
					for(int G=-9;G<10;G++){
						if(time[9]=='-' && 0<=G)
							continue;
						if(time[9]=='+' && G<0)
							continue;
						if(time[10]!='?' && abs(G)!=time[10]-'0')
							continue;
						int a=h1*10+h2;
						a-=G;
						if(a<0)
							a+=24;
						if(23<a)
							a-=24;
						hour=min(a,hour);
					} 
				}
			}
			string s;
			char c[20];
			sprintf(c,"%02d:%02d",hour,minute);
			s=c;
			return s;
		}
};

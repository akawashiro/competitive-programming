#include <string>
#include <stdio.h>
using namespace std;

class BestApproximationDiv2{
		public:
				string findFraction(int maxDen, string number);
};

int quality(string number,int a,int b)
{
		int n=(int)number.length()-2;
		for(int i=0;i<=n;i++){
				a*=10;
				if(number[i+2] != '0'+(a/b))
						return i+1;
				a-=a/b*b;
		}
		return n+1;
}

string BestApproximationDiv2::findFraction(int maxDen, string number)
{
		double num;
		sscanf(number.c_str(),"%lf",&num);
		int aa=0,ab=0,ax=0;
		for(int b=0;b<=maxDen;b++){
				int t=int(b*num);
				for(int a=max(0,t-1);a<=min(t+1,b-1);a++){
						int x=quality(number,a,b);
						if(ax < x)
								ax=x,aa=a,ab=b;
				}
		}
		char ans[100];
		sprintf(ans,"%d/%d has %d exact digits",aa,ab,ax);
		return ans;
}


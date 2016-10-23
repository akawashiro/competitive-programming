#include <vector>
#include <iostream>
using namespace std;
typedef long long LL;

class StreetWalking
{
	public:
		LL minTime(int X, int Y, int walk,	int sneak)
		{
			LL time=0;

			if(2*walk<=sneak)
			{
				time=(LL)X*(LL)walk+(LL)Y*(LL)walk;
			}
			else if(walk<=sneak && sneak<2*walk)
			{
				time+=(LL)min(X,Y)*(LL)sneak;
				time+=(LL)(max(X,Y)-min(X,Y))*(LL)walk;
			}
			else
			{
				time+=(LL)min(X,Y)*(LL)sneak;
				LL a=(LL)max(X,Y)-(LL)min(X,Y);
				LL b=(a%2==1) ? a-1 : a;
				time+=b*(LL)sneak;
				time+=a%2*(LL)walk;
			}

			return time;
		}
};


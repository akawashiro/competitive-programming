#include <string>
#include <cstdio>
using namespace std;

class LotteryTicket{
	public:
		string buy(int price, int b1, int b2, int b3, int b4)
		{
			for(int i=1;i<(1<<4);i++	)
			{
				int a=0;
				if(i & (1<<0))
					a+=b1;
				if(i & (1<<1))
					a+=b2;
				if(i & (1<<2))
					a+=b3;
				if(i & (1<<3))
					a+=b4;
				if(a==price){
					printf("a=%d\n",a);
					return "POSSIBLE";
				}
			}
			return "IMPOSSIBLE";
		}
};

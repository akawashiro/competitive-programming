#include <cstring>
#include <string>
#include <vector>

#define MOD 1234567891
typedef long long LL;
using namespace std;

class TheCardLineDivTwo
{
	public:

		int n;
		LL cache[13][2][(1<<16)];
		vector<string> cards;


		char m2n(char c)
		{
			if(c=='S')	return 0;
			if(c=='C')	return 0;
			if(c=='D')	return 1;
			if(c=='H')	return 1;
			return -1;
		}

		char n2n(char c)
		{
			if(c=='A')	return 0;
			if('2'<=c && c<='9')	return c-'1';
			if(c=='T')	return 9;
			if(c=='J')	return 10;
			if(c=='Q')	return 11;
			if(c=='K')	return 12;
			return -1;
		}

		LL rec(char num,char mark,int left)
		{
			LL &r=cache[(int)num][(int)mark][left];
			if(r!=-1)
				return r;
			if(left==0)
				return r=1;
			r=0;
			
			for(int next=0;next<n;next++)
				if( left&(1<<next) && (cards[next][0]==num || cards[next][1]==mark) )
					r=(r+rec(cards[next][0],cards[next][1],left^(1<<next)))%MOD;
			return r;
		}

		int count(vector <string> _cards)
		{
			cards=_cards;
			n=cards.size();
			for(int i=0;i<n;i++)
			{
				cards[i][0]=n2n(cards[i][0]);
				cards[i][1]=m2n(cards[i][1]);
			}
			memset(cache,-1,sizeof(cache));

			LL ans=0;
			for(int i=0;i<n;i++)
				ans=(ans+rec(cards[i][0],cards[i][1],((1<<n)-1)^(1<<i)))%MOD;

			return (int)ans;
		}
};


#include <algorithm>
#include <cstring>

using namespace std;

class BarracksEasy
{
	public:

		int unitsPerRound;
		int cache[50+1][50+1][100];

		int rec(int myUnits,int barHp,int opponentsUnits)
		{	
			//printf("myUnits=%d barHp=%d opponentsUnits=%d\n",myUnits,barHp,opponentsUnits);
		
			if(barHp==0 && opponentsUnits==0)
				return 0;
			if(myUnits==0)
				return (1<<28);
			
			int &r=cache[myUnits][barHp][opponentsUnits];
			if(0<r)
				return r;
			if(r==-3)
				return r=(1<<28);
			r--;
			int tmp=(1<<28);

			for(int killer=0;killer<=myUnits;killer++)
			{
				int breaker=myUnits-killer;
				
				int leftOpponentsUnits=max(0,opponentsUnits-killer);
				int leftOpponentHp=max(0,barHp-breaker);
				
				int leftMyUnits=max(0,myUnits-leftOpponentsUnits);
				leftOpponentsUnits+=(leftOpponentHp!=0)?unitsPerRound:0;
				
				tmp=min(tmp,1+rec(leftMyUnits,leftOpponentHp,leftOpponentsUnits));
			}
			return r=tmp;
		}

		int attack(int myUnits, int barHp, int _unitsPerRound)
		{
			unitsPerRound=_unitsPerRound;
			memset(cache,0,sizeof(cache));
			int ans=rec(myUnits,barHp,0);

			return ((1<<28)<=ans)?-1:ans;
		}
};


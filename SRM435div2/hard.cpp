#include <algorithm>
#include <cstdio>
#include <iostream>

typedef long long LL;

using namespace std;

class BirdsCounting
{
	public:

		LL comb(LL a,LL b)
		{
			LL r=1;
			for(LL i=0;i<b;i++)
				r*=(a-i);
			for(LL i=b;0<i;i--)
				r/=i;
			return r;
		}

		double calc(LL m,LL u,LL p,LL a,LL n)
		{
			if(u<a || m<p-a || n<p)
				return 0.0;

			LL x,y,z;
			x=comb(u,a),y=comb(m,p-a),z=comb(n,p);
			
			double r=(double)x*(double)y/(double)z;
			
			return r;
		}

		double computeProbability(int birdsNumber, int caughtPerDay,
				int daysNumber, int birdsMarked)
		{
			double DP[30][30];
		 	for(int i=0;i<30;i++)
				for(int j=0;j<30;j++)
					DP[i][j]=0.0;

			DP[0][0]=1.0;

			for(int day=0;day<daysNumber+1;day++)
				for(LL nowMark=0;nowMark<=birdsNumber;nowMark++)
					for(LL newMark=0;newMark<=caughtPerDay;newMark++)
						if(nowMark+newMark<=birdsNumber)
						{
							double d=DP[day][nowMark]*
								calc(nowMark,birdsNumber-nowMark,caughtPerDay,newMark,birdsNumber);
							DP[day+1][nowMark+newMark]+=d;
						}

			return DP[daysNumber][birdsMarked];
		}
};


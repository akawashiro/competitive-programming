#include <vector>
using namespace std;

class PrimeSoccer
{
	public:
		double getProbability(int skillOfTeamA, int skillOfTeamB)
		{
			vector<double> getA(20,0);
			getA[0]=1;
			vector<double> getB(20,0);
			getB[0]=1;
			for(int interval=0;interval<18;interval++)
			{
				vector<double> a(20);
				a[0]=getA[0]*(100.0-(double)skillOfTeamA)/100.0;
				vector<double> b(20);
				b[0]=getB[0]*(100.0-(double)skillOfTeamB)/100.0;
				for(int i=0;i<20-1;i++)
				{
					a[i+1]=getA[i]*(double)skillOfTeamA/100.0+getA[i+1]*(100.0-(double)skillOfTeamA)/100.0;
					b[i+1]=getB[i]*(double)skillOfTeamB/100.0+getB[i+1]*(100.0-(double)skillOfTeamB)/100.0;
				}
				getA=a;
				getB=b;
			}
			double probA=0;
			double probB=0;
			for(int i=1;i<20;i++)
				if(i==2 || i==3 || i==5 || i==7 || i==11 || i==13 || i==17)
				{
					probA+=getA[i];
					probB+=getB[i];
				}
			return 1.0-(1.0-probA)*(1.0-probB);
		}
};

#include <vector>

using namespace std;

void show(vector<double> v)
{
	for(int i=0;i<(int)v.size();i++)
		printf("%4.4lf ",v[i]);
	printf("\n");
}

class CrazyRunning
{
	public:
		double expectedTime(vector<int> corridors)
		{
			int n=corridors.size();
			double s2c=corridors[0]*2;
			double otherAve=0.0;
			for(int i=1;i<n;i++)
				otherAve+=corridors[i];
			otherAve/=(double)(n-1);

			double ans=0.0;
			vector<double> S(n+1,0.0);
			vector<double> O(n+1,0.0);
			vector<double> eS(n+1,0.0);
			vector<double> eO(n+1,0.0);
			S[1]=1.0,eS[1]=corridors[0];

			for(int time=0;time<1000;time++)
			{
				show(S);
				show(O);
				printf("\n");
				
				vector<double> nS(n+1,0.0);
				vector<double> nO(n+1,0.0);
				vector<double> neS(n+1,0.0);
				vector<double> neO(n+1,0.0);

				for(int v=1;v<n;v++)
				{
					double d=S[v]*(double)(v-1)/(double)(n-1);
					double e=S[v]*(double)(n-v)/(double)(n-1);
					nO[v]  +=d;
					nO[v+1]+=e;
					neO[v]  +=(eS[v]+otherAve)*d;
					neO[v+1]+=(eS[v]+otherAve)*e;
				}
				for(int v=2;v<n;v++)
				{
					double d=1.0/(double)(n-1);
					double e=O[v]*(double)(v-2)/(double)(n-1);
					double f=O[v]*(double)(n-v+1)/(double)(n-1);
					nS[v]  +=d;
					nO[v]  +=e;
					nO[v+1]+=f;
					neS[v]  +=(eO[v]+s2c)*d;
					neO[v]  +=(eO[v]+otherAve)*e;
					neO[v+1]+=(eO[v]+otherAve)*f;
				}
				
				show(nS);
				show(nO);
				printf("\n");
				
				ans+=neO[n];
				nO[n]=0.0;
				neO[n]=0.0;

				S=nS;
				O=nO;
			}

			return ans;
		}
};


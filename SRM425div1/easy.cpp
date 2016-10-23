#include <string>
#include <set>
#include <utility>
using namespace std;

int n;
double east,west,south,north;
bool isVisited[3000];

double DFS(int step,double prob,int x,int y)
{
	if(isVisited[x*100+y+1500])
		return 0.0;
	if(step==n)
		return prob;
	else
	{
		double r=0.0;
		step++;
		isVisited[x*100+y+1500]=true;
		r+=DFS(step,prob*north,x,y-1);
		r+=DFS(step,prob*south,x,y+1);
		r+=DFS(step,prob*east,x+1,y);
		r+=DFS(step,prob*west,x-1,y);
		isVisited[x*100+y+1500]=false;;
		return r;
	}
};


class CrazyBot
{
	public:
		double getProbability(int _n, int _east, int _west, int _south, int _north)
		{
			n=_n;
			east=_east;east/=100;
			west=_west;west/=100;
			north=_north;north/=100;
			south=_south;south/=100;
			memset(isVisited,false,sizeof(isVisited));
			return DFS(0,1,0,0);
		}
};

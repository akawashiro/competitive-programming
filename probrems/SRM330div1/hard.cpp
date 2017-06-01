// this is copy syda's
#include <vector>
using namespace std;

class LonLongNim{
	public:
		int numbersOfWins(int,vector<int>);
};

int d[50000000];
int last[1<<22];

int LonLongNim::numbersOfWins(int n,vector<int> moves)
{
	d[0]=1;
	for(int i=1;i<=4900000;i++){
		d[i]=1;
		for(int j=0;j<moves.size();j++)
			if(moves[j]<=i && d[i-moves[j]]==1)
				d[i]=0;
	}
	int predperiod=0,period=0;
	for(int i=21;i<=49000000;i++){
		int mask=0;
		for(int j=i-21;j<=i;j++)
			mask+=d[j] ? (1<<(i-j)) : 0;
		if(last[mask]==0)
			last[mask]=i;
		else{
			predperiod=last[mask]-1;
			period=i-last[mask];
			break;
		}
	}
	if(n<=predperiod){
		int res=0;
		for(int i=1;i<=n;i++)
			res+=d[i];
		return res;
	}
	int u=(n-predperiod)/period;
	int v=(n-predperiod)/period;
	int res=0;
	for(int i=1;i<=predperiod;i++)
		res+=d[i];
	for(int i=predperiod+1;i<=predperiod+period;i++){
		res+=d[i]*u;
		res+=(i-predperiod)<=v ? d[i] :0;
	}
	return res;
}


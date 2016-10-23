#include <cstring>
#include <string>
#define MOD 999983  

typedef long long LL;
using namespace std;

class CharmingTicketsEasy
{
	public:

		LL DP[70][500];

		int count(int K, string good)
		{
			memset(DP,0,sizeof(DP));
			DP[0][0]=1;
			for(int i=0;i<K;i++)
				for(int j=0;j<460;j++)
					for(int k=0;k<(int)good.size();k++)
					{
						DP[i+1][j+good[k]-'0']+=DP[i][j];
						DP[i+1][j+good[k]-'0']%=MOD;
					}

			LL U=0;
			for(int i=0;i<460;i++)							//n(P)+n(Q)をUとしている
				U=(U+(DP[K][i]*DP[K][i])*2)%MOD;	//＊１

			LL P=0;
			for(int half=0;half<460;half++)
				for(int quarter=0;quarter<=half;quarter++)
				{
					LL a=DP[K-K/2][quarter]*DP[K/2][half-quarter];
					a%=MOD;					//Pはn(P∩Q)
					P=(P+a*a)%MOD;	//＊２
				}

			return ((U-P)%MOD+MOD)%MOD;
		}
};


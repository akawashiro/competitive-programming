#include <string>
typedef  long long LL;
using namespace std;

class LotteryCheating
{
	public:
		int minimalChange(string ID)
		{
			LL nNum=0;
			LL nID=0;
			for(LL i=0,j=1;i<ID.size();i++,j*=10){
				if(ID[i]!='0')
					nNum++;
				nID+=(ID[ID.size()-i-1]-'0')*j;
			}
			int maxMatch=0;
			LL limit=1;
			for(int i=0;i<ID.size();i++)
				limit*=10;
			for(LL i=0;(LL)i*i<limit;i++){
				LL a=i*i;
				LL b=nID;
				int match=0;
				for(int j=0;j<10;j++){
					if(a%10 == b%10)
						match++;
					a=(a!=0) ? a/10 : 0;
					b=(b!=0) ? b/10 : 0;
				}
				maxMatch=max(maxMatch,match);
			}
			return 10-maxMatch;
		}
};

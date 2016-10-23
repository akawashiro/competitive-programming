#include <string>
using namespace std;

class StripePainter{
	public:

		int dp[50][50];
		string str;

		int rec(int s,int e)
		{
			if(s==e)			return 1;
			if(dp[s][e]!=-1)	return dp[s][e];
			if(e<s)				return 100;
			if(s<0 || e<0 || str.size()<=s || str.size()<=e)	return 100;
			dp[s][e]=100;
			for(int i=s;i<e;i++)
				dp[s][e]=min(dp[s][e],rec(s,i)+rec(i+1,e)-(str[s]==str[e])?1:0);
			return dp[s][e];
		}

		int minStrokes(string stripes)
		{
			for(int i=0;i<50;i++)
				for(int j=0;j<50;j++)
					dp[i][j]=-1;
			str=stripes;
			return rec(0,str.size()-1);
		}
};

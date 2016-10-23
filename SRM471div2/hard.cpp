#include <string>
#include <vector>
#include <limits.h>
using namespace std;

class Thirteen{
	public:

		int c2t(char c)
		{
			if(c=='#')
				return INT_MAX;
			if('A'<=c && c<='Z')
				return c-'A'+1;
			if('a'<=c && c<='z')
				return c-'a'+27;
		}

		int calcTime(vector <string> city)
		{
			int n=city.size();
			int dist[n][13];
			int isVisted[n][13];
			for(int i=0;i<n;i++)
				for(int j=0;j<13;j++){
					dist[i][j]=INT_MAX;
					isVisted[i][j]=false;
				}

			dist[0][0]=0;
			isVisted[0][0]=true;
			while(1){
				int d=INT_MAX,u1=INT_MAX,u2=INT_MAX;
				for(int i1=0;i1<n;i1++)
					for(int i2=0;i2<13;i2++)
						for(int j1=0;j1<n;j1++)
							if(c2t(city[i1][j1])!=INT_MAX && dist[i1][i2]!=INT_MAX){
								int a=dist[i1][i2]+c2t(city[i1][j1]);
								if(a<d && a%13!=0 && !isVisted[j1][a%13]){
									d=a;
									u1=j1;
									u2=a%13;
								}
							}
				if(d==INT_MAX)
					break;
				//printf("dist[%d][%d]=%d\n",u1,u2,d);
				dist[u1][u2]=d;
				isVisted[u1][u2]=true;
			}

			int ans=INT_MAX;
			for(int i=0;i<13;i++)
				ans=min(dist[n-1][i],ans);
			ans=(ans==INT_MAX) ? -1 : ans;
			return ans;
		}
};

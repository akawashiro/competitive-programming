#include <vector>
using namespace std;

class TheFansAndMeetingsDivTwo{
	public:
		double find(vector <int> minJ, vector <int> maxJ, vector <int> minB, vector <int> maxB)
		{
			double probJ[51];
			double probB[51];
			double ans=0;
			for(int i=0;i<51;i++)
				probJ[i]=0,probB[i]=0;

			for(int i=0;i<minJ.size();i++)
				for(int j=minJ[i];j<=maxJ[i];j++)
					probJ[j]+=1.0/minJ.size()/(maxJ[i]-minJ[i]+1);

			for(int i=0;i<minB.size();i++)
				for(int j=minB[i];j<=maxB[i];j++)
					probB[j]+=1.0/minB.size()/(maxB[i]-minB[i]+1);

			for(int i=0;i<51;i++){
				//	printf("probJ[%d]=%lf probB[%d]=%lf\n",i,probJ[i],i,probB[i]);
				ans+=probJ[i]*probB[i];
			}
			return ans;
		}
};

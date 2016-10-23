#include <vector>
using namespace std;

class TheSoccerDivTwo{
	public:
		int find(vector <int> points)
		{
			int gd=0,gu=0,g12=0,g3=0,n=points.size(),upper=0;
			for(int i=1;i<n;i++){
				int dif=points[i]-points[0];
				if(dif<=0)
					gd++;
				else if(4<=dif)
					gu++;
				else if(dif==1 || dif==2)
					g12++;
				else if(dif==3)
					g3++;
			}
			gu++;
			printf("gu=%d gd=%d g12=%d g3=%d\n",gu,gd,g12,g3);
			upper+=gu;
			g3+=g12%2;
			if(g3<=gu+gd)
				return upper;
			else
				upper+=(g3-gu-gd)/2;
			return upper;
		}
};

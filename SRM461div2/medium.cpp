#include <vector>
#include <math.h>
#include <algorithm>
#include <functional>
using namespace std;

class ColoringRectangle{
	public:
		int chooseDisks(int Cwidth, int Cheight, vector <int> red, vector <int> blue)
		{
			double width=Cwidth;
			double height=Cheight;
			vector<double> coverRed;
			vector<double> coverBlue;
			for(int i=0;i<red.size();i++)
				if(height<=red[i])
					coverRed.push_back(sqrt((double)red[i]*red[i]-(double)height*height));
			for(int i=0;i<blue.size();i++)
				if(height<=blue[i])
					coverBlue.push_back(sqrt((double)blue[i]*blue[i]-(double)height*height));
			sort(coverRed.begin(),coverRed.end(),greater<double>());
			sort(coverBlue.begin(),coverBlue.end(),greater<double>());
			//printf("coverRed=%d coverBlue=%d\n",coverRed.size(),coverBlue.size());
			int iRed=0;
			int iBlue=0;
			int nCircle1=0;
			double oldWidth=width;
			while(1){
				if(coverRed.size()<=iRed)
					break;
				else{
					width-=coverRed[iRed];
					iRed++;
					nCircle1++;
				}
				if(width<=0)
					break;
				//printf("width=%lf\n",width);
				if(coverBlue.size()<=iBlue)
					break;
				else{
					width-=coverBlue[iBlue];
					iBlue++;
					nCircle1++;
				}
				if(width<=0)
					break;
				//printf("width=%lf\n",width);
			}
			if(0<width)
				nCircle1=1000;

			width=oldWidth;
			iRed=0;
			iBlue=0;
			int nCircle2=0;
			while(1){
				if(coverBlue.size()<=iBlue)
					break;
				else{
					width-=coverBlue[iBlue];
					iBlue++;
					nCircle2++;
				}
				if(width<=0)
					break;
				//printf("width=%lf\n",width);
				if(coverRed.size()<=iRed)
					break;
				else{
					width-=coverRed[iRed];
					iRed++;
					nCircle2++;
				}
				if(width<=0)
					break;
				//printf("width=%lf\n",width);
			}
			if(0<width)
				nCircle2=1000;
			//printf("%d %d\n",nCircle1,nCircle2);
			int ans=min(nCircle1,nCircle2);
			if(ans!=1000)
				return ans;
			return -1;
		}
};

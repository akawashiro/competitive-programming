#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class ShipLoading
{
	public:
		int minimumTime(vector <int> cranes, vector <string> _boxes)
		{
			vector<int> boxes;
			stringstream ss;
			for(int i=0;i<_boxes.size();i++)
				ss << _boxes[i];
			int a;
			while(ss >> a)
				boxes.push_back(a);


			int nB=boxes.size(),nC=cranes.size();
			vector<int> isMoved(nB,false);

			sort(cranes.begin(),cranes.end());
			reverse(cranes.begin(),cranes.end());
			sort(boxes.begin(),boxes.end());
			reverse(boxes.begin(),boxes.end());
			if(cranes[0] < boxes[0])
				return -1;

			int ans;
			for(ans=0;count(isMoved.begin(),isMoved.end(),true)!=nB;ans++)
			{
				for(int c=0;c<nC;c++)
					for(int b=0;b<nB;b++)
						if(!isMoved[b] && boxes[b]<=cranes[c])
						{
							isMoved[b]=true;
							break;
						}
			}
			return ans;
		}
};


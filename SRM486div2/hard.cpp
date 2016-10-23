#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class CrazyLine{
		public:
				int maxCrazyness(vector<int> heights);
};

int CrazyLine::maxCrazyness(vector<int> heights)
{
		int n=heights.size();
		if(n==1)
				return 0;
		sort(heights.begin(),heights.end());
		if(n%2==0){
				int crazyness=0;
				for(int i=0;i<heights.size();i++){
						int a=((i==n/2-1 || i==n/2) ? heights[i] : heights[i]*2);
						if(i<n/2)
								crazyness-=a;
						else
								crazyness+=a;
				}
				return crazyness;
		}else{
				cout << "n%2==1\n";
				int crazyness=0;
				for(int i=0;i<heights.size();i++){
						if(i<n/2-1)
								crazyness-=heights[i]*2;
						else if(n/2+1<i)
								crazyness+=heights[i]*2;
				}
				int ans=max(crazyness-2*heights[n/2-1]+heights[n/2]+heights[n/2+1],
								crazyness-heights[n/2-1]-heights[n/2]+2*heights[n/2+1]);
				return ans;
		}
}


#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int n;

void solve()
{
	vector<int> vertex;
	
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin >> x >> y;
		vertex.push_back((x<<16)+y);
	}
	sort(vertex.begin(),vertex.end());

	int ans=0;
	for(int p1=0;p1<n;p1++)
		for(int p2=p1+1;p2<n;p2++)
		{
			int x1=vertex[p1]>>16,y1=vertex[p1]&0xffff;
			int x2=vertex[p2]>>16,y2=vertex[p2]&0xffff;
			int xdiff=x2-x1,ydiff=y1-y2;

			int x3=x1+ydiff,y3=y1+xdiff;
			int x4=x2+ydiff,y4=y2+xdiff;
			
			//printf("(%d,%d),(%d,%d),(%d,%d),

			if(0<=x3 && 0<=y3 && 0<=x4 && 0<=y4)
			{
				if( binary_search(vertex.begin(),vertex.end(),
							((x3<<16)+y3))
						&& binary_search(vertex.begin(),vertex.end(),
							((x4<<16)+y4)) )
				{
					int a=(xdiff*xdiff+ydiff*ydiff);
					ans=max(ans,a);
				}
			}
		}

	cout << ans << endl;
}

int main()
{
	while(1)
	{
		cin >> n;
		if(n==0)
			break;
		solve();
	}
	return 0;
}


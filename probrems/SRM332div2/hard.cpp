#include <string>
#include <vector>

using namespace std;

class Squares
{
	public:
		int countSquares(vector <string> field)
		{
			int ans=0,h=field[0].size(),w=field.size(),n=55;

			for(int x1=0;x1<n;x1++)
				for(int y1=0;y1<n;y1++)
					for(int xd=0;xd<n;xd++)
						for(int yd=1;yd<n;yd++)
						{
							int x2=x1+xd,y2=y1+yd;
							int x3=x1+yd,y3=y1-xd;
							int x4=x1+yd+xd,y4=y1-xd+yd;
							if(0<=x1 && x1<w && 0<=y1 && y1<h &&
									0<=x2 && x2<w && 0<=y2 && y2<h &&
									0<=x3 && x3<w && 0<=y3 && y3<h &&
									0<=x4 && x4<w && 0<=y4 && y4<h &&
									field[x1][y1]==field[x2][y2] &&
									field[x1][y1]==field[x3][y3] &&
									field[x1][y1]==field[x4][y4])
								ans++;
						}

			return ans;
		}
};


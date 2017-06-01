#include <string>
#include <vector>
using namespace std;

class CubeWalking
{
	public:
		string finalPosition(string movement)
		{
			string cube[3][3]={{"RED","BLUE","RED"},
				{"BLUE","GREEN","BLUE"},
				{"RED","BLUE","RED"}};
			int x=1,y=1,mx=0,my=1;
			for(int i=0;i<movement.size();i++)
			{
				int a=mx,b=my;
				if(movement[i]=='L')
					mx=b,my=-1*a;
				if(movement[i]=='R')
					mx=-1*b,my=a;
				if(movement[i]=='W')
					x+=mx,y+=my,x=(x+3)%3,y=(y+3)%3;
			}
			return cube[x][y];
		}
};

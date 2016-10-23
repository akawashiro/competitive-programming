#include <iostream>
using namespace std;

class POSITION{
		public:
				int x;
				int y;
};

POSITION star[1000];
POSITION constle[200];
int n,m;

bool isexist(int x,int y)
{
		for(int i=0;i<n;i++){
				if(star[i].x==x && star[i].y==y)
						return true;
		}
		return false;
}

int main()
{
		cin >> m;
		for(int i=0;i<m;i++){
				cin >> constle[i].x;
				cin >> constle[i].y;
				
				//cout << constle[i].x << " " << constle[i].y << endl;

		}
		cin >> n;
		for(int i=0;i<n;i++){
				cin >> star[i].x;
				cin >> star[i].y;

				//cout << star[i].x << " " << star[i].y << endl;
		}
		int xdif,ydif;
		for(int i=0;i<n;i++){
				xdif=star[i].x-constle[0].x;
				ydif=star[i].y-constle[0].y;

				//cout << xdif << " " << ydif << endl;

				bool isright=true;
				for(int j=1;j<m;j++){
						if(!isexist(constle[j].x+xdif,constle[j].y+ydif)){
								isright=false;
								break;
						}
				}
				if(isright)
						break;
		}
		cout << xdif << " " << ydif << endl;
		return 0;
}


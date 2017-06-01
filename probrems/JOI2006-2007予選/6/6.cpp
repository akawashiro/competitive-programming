#include <iostream>
using namespace std;

int map[18][18];
int a,b;

int search(int x,int y)
{

		//cout << "search(" << x << "," << y << ")" << endl;

		if(map[x][y]==2)
				return 1;

		int r=0;
		if(map[x+1][y]!=0)
				r+=search(x+1,y);
		if(map[x][y+1]!=0)
				r+=search(x,y+1);

		return r;
}

int main()
{
		cin >> a >> b;
		for(int i=0;i<18;i++)
				for(int j=0;j<18;j++)
						map[i][j]=0;
		for(int i=1;i<=a;i++)
				for(int j=1;j<=b;j++)
						map[i][j]=1;
		map[a][b]=2;
		int n;
		cin >> n;
		for(int i=0;i<n;i++){
				int a,b;
				cin >> a >> b;
				map[a][b]=0;
		}

		cout << search(1,1) << endl;

		return 0;
}

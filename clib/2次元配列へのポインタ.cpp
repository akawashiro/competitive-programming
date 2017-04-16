#include <iostream>
using namespace std;

void disp1(int map[10][10]);
void disp2(int (*map)[10]);

int main()
{
		int map[10][10];
		for(int i=0;i<10;i++){
				for(int j=0;j<10;j++){
						map[i][j]=i*j;
				}
		}
		disp1(map);
		disp2(map);
}

void disp1(int map[10][10])
{
		for(int i=0;i<10;i++){
				for(int j=0;j<10;j++){
						cout << map[i][j] ;
				}
				cout << endl;
		}
}

void disp2(int (*map)[10])
{
		for(int i=0;i<10;i++){
				for(int j=0;j<10;j++){
						cout << map[i][j] ;
				}
				cout << endl;
		}
}

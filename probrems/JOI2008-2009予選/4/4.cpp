#include <iostream>
using namespace std;

int m,n;

int play(int y,int x,int square[92][92],int breaked)
{
		if(square[y][x]==0){
				return breaked;
		}
		square[y][x]=0;
		breaked++;
		int max=0;
		int a=play(y+1,x,square,breaked);
		max = (max<a) ? a: max;
		a=play(y-1,x,square,breaked);
		max = (max<a) ? a: max;
		a=play(y,x+1,square,breaked);
		max = (max<a) ? a: max;
		a=play(y,x-1,square,breaked);
		max = (max<a) ? a: max;

		square[y][x]=1;
		return max;
}

int main()
{
		cin >> m >> n;
		int square[92][92];
		for(int i=0;i<n+2;i++)
				for(int j=0;j<m+2;j++)
						square[i][j]=0;
		for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
						cin >> square[i][j];
		int max=0;
		for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
						int a=play(i,j,square,0);
						max = (max<a) ? a: max;
				}
		}
		cout << max << endl;
}

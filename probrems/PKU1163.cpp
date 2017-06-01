#include <stdio.h>
#include <algorithm>

using namespace std;

int rows[100+10][100+10];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<i+1;j++)
			scanf("%d",&rows[i][j]);
	for(int h=n-2;0<=h;h--)
		for(int x=0;x<h+1;x++)
			rows[h][x]+=max(rows[h+1][x],rows[h+1][x+1]);
	printf("%d\n",rows[0][0]);
	return 0;
}


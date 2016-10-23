#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <map>

using namespace std;
typedef long long LL;

int memo[1000+1][1000+1][3];

int main()
{
	int h,w;
	cin >> h >> w;
	int time;
	cin >> time;

	char star[1000][1000];
	for(int i=0;i<h;i++)
		scanf("%s",star[i]);

	for(int y=0;y<=h;y++)
		for(int x=0;x<=w;x++)
			memo[y][x][0]=memo[y][x][1]=memo[y][x][2]=0;

	for(int y=1;y<=h;y++)
		for(int x=1;x<=w;x++)
		{
			memo[y][x][0]=memo[y][x-1][0];
			memo[y][x][1]=memo[y][x-1][1];
			memo[y][x][2]=memo[y][x-1][2];

			if(star[y-1][x-1]=='J')
				memo[y][x][0]++;
			if(star[y-1][x-1]=='O')
				memo[y][x][1]++;
			if(star[y-1][x-1]=='I')
				memo[y][x][2]++;
		}

	for(int y=1;y<=h;y++)
	{
		for(int x=1;x<=w;x++)
		{
			memo[y][x][0]+=memo[y-1][x][0];
			memo[y][x][1]+=memo[y-1][x][1];
			memo[y][x][2]+=memo[y-1][x][2];
		}
	}

	for(time;0<time;time--)
	{
		int l,r,b,c;
		cin >> b >> l >> c >> r;

		int J=0,O=0,I=0;
		J=(memo[c][r][0]-memo[b-1][r][0]-memo[c][l-1][0]+memo[b-1][l-1][0]);
		O=(memo[c][r][1]-memo[b-1][r][1]-memo[c][l-1][1]+memo[b-1][l-1][1]);
		I=(memo[c][r][2]-memo[b-1][r][2]-memo[c][l-1][2]+memo[b-1][l-1][2]);

		cout << J << " " << O << " " << I << endl;
	}
	return 0;
}


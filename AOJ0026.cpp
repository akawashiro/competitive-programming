#include <cstdio>	//this means #include <stdio.h>

int big[13][2]={{-2,0},{2,0},{0,-2},{0,2},{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
int medium[9][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
int small[5][2]={{-1,0},{0,-1},{0,0},{0,1},{1,0}};

void solve()
{
	int paper[10][10];
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			paper[i][j]=0;
	int x,y,s;
	while(scanf("%d,%d,%d",&x,&y,&s)==3)	//scanfは代入に成功した変数の数を返す
	{
		if(s==3)
			for(int i=0;i<13;i++)
			{
				int xx=x+big[i][0],yy=y+big[i][1];
				if(0<=xx && xx<10 && 0<=yy && yy<10)
					paper[xx][yy]++;
			}
		else if(s==2)
			for(int i=0;i<9;i++)
			{
				int xx=x+medium[i][0],yy=y+medium[i][1];
				if(0<=xx && xx<10 && 0<=yy && yy<10)
					paper[xx][yy]++;
			}
		else
			for(int i=0;i<5;i++)
			{
				int xx=x+small[i][0],yy=y+small[i][1];
				if(0<=xx && xx<10 && 0<=yy && yy<10)
					paper[xx][yy]++;
			}
	}

	int numWhite=0;	//number of whiteの略
	int darkest=0;	//darkの最上級

	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		{
			if(paper[i][j]==0)
				numWhite++;
			if(darkest<paper[i][j])
				darkest=paper[i][j];
		}

	printf("%d\n%d\n",numWhite,darkest);
	return;
}

int main()
{
	solve();
	return 0;
}


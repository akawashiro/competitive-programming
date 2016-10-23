#include <stdio.h>
#include <string.h>

int mv[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
char board[10][10];

int nRev(char stone,int y,int x)
{
	int res=0;
	char opo=(stone=='o')?'x':'o';
	if(board[y][x]!='.')
		return 0;
	for(int m=0;m<8;m++){
		int yy=y+mv[m][0],xx=x+mv[m][1],rr=0;
		if(yy<0||8<=yy||xx<0||8<=xx||board[yy][xx]!=opo)
			continue;
		//printf("yy=%d xx=%d stone=%c opo=%c board[yy][xx]=%c\n",yy,xx,stone,opo,board[yy][xx]);
		while(0<=yy&&yy<8&&0<=xx&&xx<8&&board[yy][xx]==opo){
			rr++,yy+=mv[m][0],xx+=mv[m][1];
			//printf("yy=%d xx=%d\n",yy,xx);
		}
		if(0<=yy&&yy<8&&0<=xx&&xx<8&&board[yy][xx]==stone)
			res+=rr;
	}
	return res;
}

void ret(char stone,int y,int x)
{
	char opo=(stone=='o')?'x':'o';
	for(int m=0;m<8;m++){
		int yy=y+mv[m][0],xx=x+mv[m][1];
		if(yy<0||8<=yy||xx<0||8<=xx||board[yy][xx]!=opo)
			continue;
		//printf("yy=%d xx=%d\n",yy,xx);
		while(0<=yy&&yy<8&&0<=xx&&xx<8&&board[yy][xx]==opo)
			yy+=mv[m][0],xx+=mv[m][1];
		if(0<=yy&&yy<8&&0<=xx&&x<8&&board[yy][xx]==stone){
			yy=y+mv[m][0],xx=x+mv[m][1];
			while(0<=yy&&yy<8&&0<=xx&&xx<8&&board[yy][xx]==opo)
				board[yy][xx]=stone,yy+=mv[m][0],xx+=mv[m][1];
		}
	}
}

int main()
{
	for(int i=0;i<8;i++)
		scanf("%s",board[i]);
	for(int time=0;time<100;time++){
		int rev=0,py,px;
		for(int y=0;y<8;y++)
			for(int x=0;x<8;x++)
				if(rev<nRev('o',y,x))
					rev=nRev('o',y,x),py=y,px=x;
		//printf("rev=%d py=%d px=%d\n",rev,py,px);
		if(0<rev)
			ret('o',py,px),board[py][px]='o';
		rev=0;
		for(int y=7;0<=y;y--)
			for(int x=7;0<=x;x--)
				if(rev<nRev('x',y,x))
					rev=nRev('x',y,x),py=y,px=x;
		if(0<rev)
			ret('x',py,px),board[py][px]='x';
		//printf("rev=%d py=%d px=%d\n",rev,py,px);
	}
	for(int i=0;i<8;i++)
		printf("%s\n",board[i]);
	return 0;
}




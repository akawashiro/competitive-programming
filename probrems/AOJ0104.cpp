#include <stdio.h>
#include <string.h>
char tile[200][200];
int used[200][200];
int main()
{
	while(1){
		int h,w;
		scanf("%d%d",&h,&w);
		if(!h && !w)
			break;
		for(int i=0;i<h;i++)
			scanf("%s",tile[i]);
		memset(used,0,sizeof(used));
		int y=0,x=0;
		while(1){
			if(used[y][x] || tile[y][x]=='.')
				break;
			used[y][x]=1;
			if(tile[y][x]=='>')
				x++;
			else if(tile[y][x]=='<')
				x--;
			else if(tile[y][x]=='^')
				y--;
			else if(tile[y][x]=='v')
				y++;
		}
		if(used[y][x])
			printf("LOOP\n");
		else 
			printf("%d %d\n",x,y);
	}
	return 0;
}


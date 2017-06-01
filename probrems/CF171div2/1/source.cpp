#include <stdio.h>

int mv[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
int visit[220][220];

int main(){
     int gx,gy;
     scanf("%d%d",&gx,&gy);
     int ans=0,m=3,x=1,y=0;
     visit[100][100]=1;visit[101][100]=1;
     if(gx==0&&gy==0){
	  printf("0\n");
	  return 0;
     }
     while(1){
	  if(x==gx&&y==gy)
	       break;
	  if(!visit[x+mv[(m+1)%4][0]+100][y+mv[(m+1)%4][1]+100]){
	       m=(m+1)%4;
	       ans++;
	  }
	  x+=mv[m][0],y+=mv[m][1];
	  visit[x+100][y+100]=1;
	  // printf("x=%d y=%d\n",x,y);
     }
     printf("%d\n",ans);
     return 0;
}

	  
     

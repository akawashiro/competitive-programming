//AOJ0209
#include <stdio.h>
int scape[100][100];
int photo[50][50];
int tmp[50][50];
int main(){
	while(1){
		int n,m;
		scanf("%d%d",&n,&m);
		if(!n)	break;
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&scape[i][j]);
		for(int i=0;i<m;i++)for(int j=0;j<m;j++)scanf("%d",&photo[i][j]);
		int ansy=n,ansx=n;
		for(int i=0;i<4;i++){
			for(int sy=0;sy<n&&sy+m-1<n;sy++)
				for(int sx=0;sx<n&&sx+m-1<n;sx++){
					int b=1,f=1,ay,ax;
					for(int y=0;y<m;y++)
						for(int x=0;x<m;x++){
							if(photo[y][x]!=-1&&scape[sy+y][sx+x]!=photo[y][x]){
								b=0;
								y=m,x=m;
							}
							if(f&&scape[sy+y][sx+x]==photo[y][x]){
								f=0;
								ay=sy+y,ax=sx+x;
							}
						}
					if(b){
						if(ay<ansy||(ay==ansy&&ax<ansx))
							ansy=ay,ansx=ax;
					}
				}

			/*for(int j=0;j<m;j++){
				for(int k=0;k<m;k++)
					printf("%d ",photo[j][k]);
				printf("\n");
			}
			printf("\n");*/
			for(int j=0;j<m;j++)
				for(int k=0;k<m;k++)
					tmp[k][m-1-j]=photo[j][k];
			for(int j=0;j<m;j++)
				for(int k=0;k<m;k++)
					photo[j][k]=tmp[j][k];
		}
		if(ansx==n)	printf("NA\n");
		else		printf("%d %d\n",ansx+1,ansy+1);
	}
	return 0;
}


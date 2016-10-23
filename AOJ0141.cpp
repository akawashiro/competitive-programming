//AOJ0141
#include <stdio.h>
int mv[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int sp[100][100];
int main(){
	int M;
	scanf("%d",&M);
	for(int T=0;T<M;T++){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				sp[i][j]=' ';
		int m=0;
		int yy,xx,yyy,xxx,l;
		int y=n-1,x=0;
		while(1){
			l=0;
			while(1){

				/*for(int i=0;i<n;i++){
					for(int j=0;j<n;j++)
						printf("%c",sp[i][j]);
					printf("\n");
				}
				printf("----------\n");*/

				sp[y][x]='#';
				l++;
				yy=y+mv[m][0],xx=x+mv[m][1];
				yyy=y+mv[m][0]*2,xxx=x+mv[m][1]*2;
				if(yy<0||n<=yy||xx<0||n<=xx||
						(0<=yyy&&yyy<n&&0<=xxx&&xxx<n&&sp[yyy][xxx]=='#')){
					m=(m+1)%4;
					break;
				}
				y=yy,x=xx;
			}
			yy=y+mv[m][0],xx=x+mv[m][1];
			yyy=y+mv[m][0]*2,xxx=x+mv[m][1]*2;
			if(yy<0||n<=yy||xx<0||n<=xx||yyy<0||n<=yyy||xxx<0||n<=xxx||
					sp[yyy][xxx]=='#'||l==2)
				break;
		}
		if(T)
			printf("\n");
		if(n==2)
			printf("##\n# \n");
		else
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++)
					printf("%c",sp[i][j]);
				printf("\n");
			}
	}
	return 0;
}





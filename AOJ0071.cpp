//AOJ0071
#include <stdio.h>
#include <queue>
using namespace std;
int f[8][8];
int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		for(int i=0;i<8;i++)
			for(int j=0;j<8;j++){
				char c='u';
				while(c!='1'&&c!='0')
					c=getchar();
				f[i][j]=c-'0';
			}
		int x,y,r=0;
		scanf("%d%d",&x,&y);
		x--,y--;
		queue<int> qx,qy;
		qx.push(x),qy.push(y);
		while(!qx.empty()){
			x=qx.front(),y=qy.front();
			qx.pop(),qy.pop();
			if(0<=y&&y<8&&0<=x&&x<8&&f[y][x]==1){
				r++;
				f[y][x]=0;
				for(int i=-3;i<=3;i++){
					qx.push(x+i),qy.push(y);
					qx.push(x),qy.push(y+i);
				}
			}
		}
		printf("Data %d:\n",t);
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++)
				printf("%d",f[i][j]);
			printf("\n");
		}
	}
	return 0;
}


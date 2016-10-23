
//AOJ0223
#include <stdio.h>
//AOJ0223
#include <queue>
#include <string.h>
using namespace std;

int mv[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int depart[50][50];
int time[50][50][50][50];

int ke(int a,int b,int c,int d)
{
	return a*125000+b*2500+c*50+d;
}

void kd(int *a,int *b,int *c,int *d,int k)
{
	*d=k%50;k/=50;
	*c=k%50;k/=50;
	*b=k%50;k/=50;
	*a=k%50;k/=50;
}

int main()
{
	while(1){
		int h,w,tx,ty,kx,ky;
		scanf("%d%d",&w,&h);
		if(!w&&!h)
			break;
		scanf("%d%d%d%d",&tx,&ty,&kx,&ky);
		tx--,ty--,kx--,ky--;
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				scanf("%d",&depart[i][j]);
		queue<int> qp,qt;
		//printf("ty=%d tx=%d ky=%d kx=%d k=%d\n",ty,tx,ky,kx,ke(ty,tx,ky,kx));
		//kd(&ty,&tx,&ky,&kx,ke(ty,tx,ky,kx));
		//printf("ty=%d tx=%d ky=%d kx=%d\n",ty,tx,ky,kx);
		qp.push(ke(ty,tx,ky,kx));
		qt.push(0);
		memset(time,-1,sizeof(time));
		int ans=1000;
		while(!qp.empty() && ans==1000){
			int k=qp.front();qp.pop();
			int t=qt.front();qt.pop();
			kd(&ty,&tx,&ky,&kx,k);
			//printf("ty=%d tx=%d ky=%d kx=%d t=%d\n",ty,tx,ky,kx,t);
			if(100<t)
				break;
			if(time[ty][tx][ky][kx]!=-1)
				continue;
			if(ty==ky&&tx==kx)
				ans=t;
			time[ty][tx][ky][kx]=t;
			for(int i=0;i<4;i++){
				int ty2=ty+mv[i][0],tx2=tx+mv[i][1];
				int ky2=ky-mv[i][0],kx2=kx-mv[i][1];
				if(ty2<0||h<=ty2||tx2<0||w<=tx2||depart[ty2][tx2]==1)
					ty2=ty,tx2=tx;
				if(ky2<0||h<=ky2||kx2<0||w<=kx2||depart[ky2][kx2]==1)
					ky2=ky,kx2=kx;
				qp.push(ke(ty2,tx2,ky2,kx2));
				qt.push(t+1);
			}
		}
		if(100<=ans)
			printf("NA\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}



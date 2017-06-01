//AOJ1176
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define INF (1<<28)
#define MAX_H 35
#define MAX_W 35
using namespace std;
struct Data{
	int group,yobi;
};
Data makeD(int g,int y){
	Data d;
	d.group=g,d.yobi=y;
	return d;
}
Data mergeD(Data d1,Data d2){
	return makeD(d1.group+d2.group,min(d1.yobi,d2.yobi));
}
bool operator < (const Data &d,const Data &e){
	if(d.group!=e.group)	return d.group<e.group;
	else					return d.yobi<e.yobi;
}
int h,w,supply;
int demand[MAX_H][MAX_W];
int S[MAX_H][MAX_W];
int visited[MAX_H][MAX_W][MAX_H][MAX_W];
Data cache[MAX_H][MAX_W][MAX_H][MAX_W];
Data rec(int y1,int x1,int y2,int x2){
	if(visited[y1][x1][y2][x2])	return cache[y1][x1][y2][x2];
	if(y1==y2||x1==x2)	return cache[y1][x1][y2][x2]=makeD(0,INF);
	Data res=makeD(0,0),d1,d2;
	if(S[h][w]-(S[y2][x2]-S[y2][x1]-S[y1][x2]+S[y1][x1])<=supply)
		res=makeD(1,supply-S[h][w]+(S[y2][x2]-S[y2][x1]-S[y1][x2]+S[y1][x1]));
	for(int i=y1+1;i<y2;i++){
		d1=rec(y1,x1,i,x2);
		d2=rec(i,x1,y2,x2);
		res=max(res,mergeD(d1,d2));
	}
	for(int i=x1+1;i<x2;i++){
		d1=rec(y1,x1,y2,i);
		d2=rec(y1,i,y2,x2);
		res=max(res,mergeD(d1,d2));
	}
	visited[y1][x1][y2][x2]=1;
	return cache[y1][x1][y2][x2]=res;
}
int main(){
	while(1){
		scanf("%d%d%d",&h,&w,&supply);
		if(h==0&&w==0)	break;
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				scanf("%d",&demand[i][j]);
		memset(S,0,sizeof(S));
		for(int i=0;i<h;i++){
			int a=0;
			for(int j=0;j<w;j++){
				a+=demand[i][j];
				S[i+1][j+1]=S[i][j+1]+a;
			}
		}
		memset(visited,0,sizeof(visited));
		Data ans=rec(0,0,h,w);
		printf("%d %d\n",ans.group,ans.yobi);
	}
	return 0;
}


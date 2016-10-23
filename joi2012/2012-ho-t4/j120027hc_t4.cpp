#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
short nails[5010][5010];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	memset(nails,0,sizeof(nails));
	for(int i=0;i<m;i++){
		int a,b,x;
		scanf("%d%d%d",&a,&b,&x);
		nails[a+x][b+x]=max(nails[a+x][b+x],(short)(x+1));
	}
	int ans=0;
	for(int y=n;0<=y;y--)
		for(int x=n;0<=x;x--){
			if(0<nails[y][x])
				ans++;
			if(0<x)
				nails[y][x-1]=max(nails[y][x-1],(short)(nails[y][x]-1));
			if(0<x&&0<y)
				nails[y-1][x-1]=max(nails[y-1][x-1],(short)(nails[y][x]-1));
		}
	printf("%d\n",ans);
	return 0;
}


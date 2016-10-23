#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int cl[100][100];
int l[100][100];
int r[100][100];
int main(){
	int n;
	while(1){
		scanf("%d",&n);
		if(!n)
			break;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&cl[i][j]);
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		for(int i=0;i<n;i++){
			int m=100000000;
			for(int j=0;j<n;j++)
				m=min(m,cl[i][j]);
			for(int j=0;j<n;j++)
				if(cl[i][j]==m)
					l[i][j]=1;
		}
		for(int i=0;i<n;i++){
			int m=-1;
			for(int j=0;j<n;j++)
				m=max(m,cl[j][i]);
			for(int j=0;j<n;j++)
				if(cl[j][i]==m)
					r[j][i]=1;
		}
		int b=0;
		for(int i=0;i<n&&!b;i++)
			for(int j=0;j<n&&!b;j++)
				if(r[i][j]&&l[i][j]){
					printf("%d\n",cl[i][j]);
					b=1;
				}
		if(!b)
			printf("0\n");
	}
	return 0;
}


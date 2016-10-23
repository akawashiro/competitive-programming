//AOJ1114
#include <stdio.h>
#include <stack>
using namespace std;
int gr[5][5];
int su[5][5];
int main(){
	int T;
	scanf("%d",&T);
	for(;0<T;T--){
		for(int i=0;i<5;i++)
			for(int j=0;j<5;j++)
				scanf("%d",&gr[i][j]);
		int ans=0;
		for(int y1=0;y1<5;y1++)
			for(int y2=y1+1;y2<=5;y2++)
				for(int x1=0;x1<5;x1++)
					for(int x2=x1+1;x2<=5;x2++){
						int b=1;
						for(int i=y1;i<y2;i++)
							for(int j=x1;j<x2;j++)
								if(!gr[i][j])
									b=0;
						if(b)
							ans=max(ans,(y2-y1)*(x2-x1));
					}
		printf("%d\n",ans);
	}
	return 0;
}


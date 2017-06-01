
/*#include <set>
#include <stdio.h>
using namespace std;
int A[500000+10],B[500000+10],X[500000+10];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);	
	for(int i=0;i<m;i++)
		scanf("%d%d%d",A+i,B+i,X+i);
	set<int> se;
	for(int i=0;i<m;i++)
		for(int y=A[i],t=1;y<=A[i]+X[i];y++,t++)
			for(int x=B[i];x<B[i]+t;x++)
				se.insert(y*10000+x);
	printf("%d\n",se.size());
	return 0;
}*/



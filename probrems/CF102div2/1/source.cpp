#include <algorithm>
#include <stdio.h>
using namespace std;
int main(){
	int r1,r2,c1,c2,d1,d2,ok=0;
	int ar[9];
	scanf("%d%d%d%d%d%d",&r1,&r2,&c1,&c2,&d1,&d2);
	for(int i=0;i<9;i++)
		ar[i]=i+1;
	do{
		if(ar[0]+ar[1]==r1&&ar[2]+ar[3]==r2&&ar[0]+ar[2]==c1&&ar[1]+ar[3]==c2&&ar[0]+ar[3]==d1&&ar[1]+ar[2]==d2){
			ok=1;
			break;
		}
		reverse(ar+4,ar+9);
	}while(next_permutation(ar,ar+9));
	if(ok)
		printf("%d %d\n%d %d\n",ar[0],ar[1],ar[2],ar[3]);
	else
		printf("-1\n");
	return 0;
}


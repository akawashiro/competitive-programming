#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int p1,p2,p3,j1,j2;
	scanf("%d%d%d%d%d",&p1,&p2,&p3,&j1,&j2);
	printf("%d\n",min(min(p1,p2),p3)+min(j1,j2)-50);
	return 0;
}


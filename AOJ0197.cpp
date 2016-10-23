#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	while(1){
		int x,y;
		scanf("%d%d",&x,&y);
		if(!x&&!y)
			break;
		if(x<y)
			swap(x,y);
		int i;
		for(i=0;y!=0;i++){
			x=x%y;
			swap(x,y);
		}
		printf("%d %d\n",x,i);
	}
	return 0;
}


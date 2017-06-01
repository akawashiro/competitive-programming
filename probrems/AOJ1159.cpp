//AOJ1159
#include <stdio.h>
#include <string.h>
int comp[50];
int main(){
	while(1){
		int n,p;
		scanf("%d%d",&n,&p);
		if(!n&&!p)	break;
		memset(comp,0,sizeof(comp));
		int r,pp=p;
		for(r=0;;r=(r+1)%n){
			if(0<pp){
				pp--;
				comp[r]++;
			}else{
				pp=comp[r];
				comp[r]=0;
			}
			if(comp[r]==p)
				break;
		}
		printf("%d\n",r);
	}
	return 0;
}


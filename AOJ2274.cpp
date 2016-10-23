//AOJ2274
#include <stdio.h>
#include <stdlib.h>
int ans[1000];
int card[1000][1000];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++)
		for(int j=0;j<n/2;j++)
			scanf("%d",&card[i][j]);
	while(1){
		for(int i=0;i<n;i++)
			ans[i]=rand()%2;
		int ok=1;
		for(int i=0;i<k;i++){
			int s=0;
			for(int j=0;j<n/2;j++)
				s+=ans[card[i][j]-1];
			if(s<n/8||3*n/8<s)
				ok=0;
		}
		if(ok)
			break;
	}
	for(int i=0;i<n;i++)
		printf("%d",ans[i]);
	printf("\n");
	return 0;
}


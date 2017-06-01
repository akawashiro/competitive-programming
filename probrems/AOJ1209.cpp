#include <stdio.h>
int DP[18][400];
int main(){
	DP[1][0]=1;
	for(int i=1;i<18;i++)
		for(int j=0;j<400;j++){
			if(0<=j-i*i)
				DP[i][j]+=DP[i][j-i*i];
			if(1<i)
				DP[i][j]+=DP[i-1][j];
			//printf("DP[%d][%d]=%d\n",i,j,DP[i][j]);
		}
	while(1){
		int n;
		scanf("%d",&n);
		if(!n)
			break;
		printf("%d\n",DP[17][n]);
	}
	return 0;
}


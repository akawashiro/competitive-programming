//AOJ1167
#include <stdio.h>
#define MAX_N 1000000
int tet[1000];
int dp1[2][MAX_N+1];
int dp2[2][MAX_N+1];
int main(){
	int m1;
	for(m1=0;(m1+1)*(m1+2)*(m1+3)/6<=MAX_N;m1++)
		tet[m1]=(m1+1)*(m1+2)*(m1+3)/6;
	for(int i=0;i<=MAX_N;i++)
		dp1[0][i]=i;
	for(int i=1;i<m1;i++)
		for(int j=0;j<=MAX_N;j++){
			dp1[i%2][j]=dp1[(i-1)%2][j];
			if(0<=j-tet[i]&&dp1[i%2][j-tet[i]]+1<dp1[i%2][j])
				dp1[i%2][j]=dp1[i%2][j-tet[i]]+1;
		}
	int m2=0;
	for(int i=0;(i+1)*(i+2)*(i+3)/6<=MAX_N;i++)
		if((i+1)*(i+2)*(i+3)/6%2==1){
			tet[m2]=(i+1)*(i+2)*(i+3)/6;
			m2++;
		}
	for(int i=0;i<=MAX_N;i++)
		dp2[0][i]=i;
	for(int i=1;i<m2;i++)
		for(int j=0;j<=MAX_N;j++){
			dp2[i%2][j]=dp2[(i-1)%2][j];
			if(0<=j-tet[i]&&dp2[i%2][j-tet[i]]+1<dp2[i%2][j])
				dp2[i%2][j]=dp2[i%2][j-tet[i]]+1;
		}
	while(1){
		int n;
		scanf("%d",&n);
		if(!n)	break;
		printf("%d ",dp1[(m1-1)%2][n]);
		printf("%d\n",dp2[(m2-1)%2][n]);
	}
	return 0;
}




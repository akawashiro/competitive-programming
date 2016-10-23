#include <stdio.h>

int t[20][20];
int main()
{
	while(1){
		int n;
		scanf("%d",&n);
		if(!n)
			break;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&t[i][j]);
		for(int i=0;i<n;i++){
			int s=0;
			for(int j=0;j<n;j++)
				s+=t[i][j];
			t[i][n]=s;
		}
		for(int j=0;j<n+1;j++){
			int s=0;
			for(int i=0;i<n;i++)
				s+=t[i][j];
			t[n][j]=s;
		}
		for(int i=0;i<n+1;i++){
			for(int j=0;j<n+1;j++)
				printf("%5d",t[i][j]);
			printf("\n");
		}
	}
	return 0;
}


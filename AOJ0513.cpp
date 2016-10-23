#include <stdio.h>
#include <algorithm>

using namespace std;

int card[2][200+10];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*2;i++)
		card[0][i]=i+1;
	for(int t=0;t<m;t++)
	{
		/*for(int i=0;i<2*n;i++)
			printf("%d ",card[t%2][i]);
		printf("\n");*/

		int k;
		scanf("%d",&k);
		//printf("k=%d\n",k);
		if(0<k)
		{
			for(int i=0;i<k;i++)
				card[(t+1)%2][i+2*n-k]=card[t%2][i];
			/*for(int i=0;i<2*n;i++)
				printf("%d ",card[(t+1)%2][i]);
			printf("\n");*/
			for(int i=k;i<2*n;i++)
				card[(t+1)%2][i-k]=card[t%2][i];
			/*for(int i=0;i<2*n;i++)
				printf("%d ",card[(t+1)%2][i]);
			printf("\n");*/
		}
		else
		{
			for(int i=0;i<n;i++)
				card[(t+1)%2][i*2]=card[t%2][i];
			for(int i=n;i<2*n;i++)
				card[(t+1)%2][(i-n)*2+1]=card[t%2][i];
		}
	}
	for(int i=0;i<2*n;i++)
		printf("%d\n",card[m%2][i]);
	return 0;
}


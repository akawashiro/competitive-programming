#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
	int n,l;
	int unsortedness[110];
	char DNA[110][60];

	scanf("%d%d",&l,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",DNA[i]);
		unsortedness[i]=0;
		for(int j=0;j<l;j++)
			for(int k=j+1;k<l;k++)
				if(DNA[i][j]>DNA[i][k])
					unsortedness[i]++;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n-1;j++)
			if(unsortedness[j]>unsortedness[j+1])
			{
				char s[110];
				strcpy(s,DNA[j]);
				strcpy(DNA[j],DNA[j+1]);
				strcpy(DNA[j+1],s);
				int a;
				a=unsortedness[j];
				unsortedness[j]=unsortedness[j+1];
				unsortedness[j+1]=a;
			}
	for(int i=0;i<n;i++)
		printf("%s\n",DNA[i]);
	return 0;
}


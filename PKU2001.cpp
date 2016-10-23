#include <stdio.h>
#include <algorithm>

using namespace std;

int pos[1000+10];
char source[1000+10][20+5];

int main()
{
	int n;
	for(n=0;;n++)
	{
		pos[n]=1;
		if(EOF==scanf("%s",source[n]))
			break;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j==i)
				continue;
			int k=0;
			while(1)
			{
				char c=source[i][k],d=source[j][k];
				if(c!=d || c=='\0' || d=='\0')
					break;
				k++;
			}
			if(source[i][k]=='\0')
				pos[i]=max(pos[i],k);
			else
				pos[i]=max(pos[i],k+1);
		}
		printf("%s ",source[i]);
		for(int j=0;j<pos[i];j++)
			printf("%c",source[i][j]);
		printf("\n");
	}
	return 0;
}


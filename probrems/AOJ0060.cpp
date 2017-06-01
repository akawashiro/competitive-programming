#include <stdio.h>
#include <string.h>

int used[11];

int main()
{
	int C1,C2,C3;
	while(scanf("%d%d%d",&C1,&C2,&C3)!=EOF)
	{
		memset(used,0,sizeof(used));
		used[C1]=used[C2]=used[C3]=1;
		int a=0;
		for(int i=1;i<=10;i++)
			if(!used[i] && i+C1+C2<=20)
				a++;
		if(4<=a)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}


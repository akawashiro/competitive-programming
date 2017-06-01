#include <stdio.h>

int main()
{
	int days;
	while(1)
	{
		scanf("%d",&days);
		if(days==0)
			return 0;
		int res=0,pay=1,con=1;
		for(int i=0,j=0;i<days;i++,j++)
		{
			if(j==con)
				con++,pay++,j=0;
			res+=pay;
		}
		printf("%d %d\n",days,res);
	}
}


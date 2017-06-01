#include <stdio.h>
int main()
{
	while(1){
		int a[5],g=0,c=0,p=0;
		for(int i=0;i<5;i++){
			scanf("%d",a+i);
			if(!a[i])
				return 0;
			g=g|(a[i]==1);
			c=c|(a[i]==2);
			p=p|(a[i]==3);
		}
		if(g+c+p==3||g+c+p==1)
			for(int i=0;i<5;i++)
				printf("3\n");
		else if(p==0)
			for(int i=0;i<5;i++)
				printf("%d\n",(a[i]==1)?1:2);
		else if(c==0)
			for(int i=0;i<5;i++)
				printf("%d\n",(a[i]==3)?1:2);
		else if(g==0)
			for(int i=0;i<5;i++)
				printf("%d\n",(a[i]==2)?1:2);
	}
}



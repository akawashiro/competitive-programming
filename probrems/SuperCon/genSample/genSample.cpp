#include <stdio.h>
#include <stdlib.h>

int f;
int e()
{
	if(f==-1)
		return rand()%21;
	else
		return f;
}

int main(int argc,char *argv[])
{
	int h,w,k;
	h=atoi(argv[1]);
	w=atoi(argv[2]);
	k=atoi(argv[3]);
	f=atoi(argv[4]);
	
	if(200<w || 200<h || 200<k)
		printf("(w,h,k)<=200\n");
	else
	{
		printf("%d, %d, %d\n",w,h,k);
		for(int i=0;i<h+1;i++)
		{
			for(int j=0;j<w-1;j++)
				printf("%d, ",e());
			printf("%d\n",e());
		}
		for(int i=0;i<w+1;i++)
		{
			for(int j=0;j<h-1;j++)
				printf("%d, ",e());
			printf("%d\n",e());
		}
	}
	return 0;
}


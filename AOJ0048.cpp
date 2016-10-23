#include <stdio.h>

int main()
{
	double w;
	while(scanf("%lf",&w)!=EOF)
	{
		if(w<=48.00)
			printf("light fly\n");
		else if(w<=51.00)
			printf("fly\n");
		else if(w<=54.00)
			printf("bantam\n");
		else if(w<=57.00)
			printf("feather\n");
		else if(w<=60.00)
			printf("light\n");
		else if(w<=64.00)
			printf("light welter\n");
		else if(w<=69.00)
			printf("welter\n");
		else if(w<=75.00)
			printf("light middle\n");
		else if(w<=81.00)
			printf("middle\n");
		else if(w<=91.00)
			printf("light heavy\n");
		else
			printf("heavy\n");
	}
	return 0;
}



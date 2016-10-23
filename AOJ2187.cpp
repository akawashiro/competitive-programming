//AOJ2187
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	for(;0<T;T--){
		int jc[9],gc[9];
		for(int i=0;i<9;i++)
			scanf("%d",gc+i);
		for(int i=0;i<9;i++)
			scanf("%d",jc+i);
		sort(jc,jc+9);
		sort(gc,gc+9);
		double u=0,g=0;
		do{
			int gp=0,jp=0;
			for(int i=0;i<9;i++)
				if(gc[i]<jc[i])
					jp+=gc[i]+jc[i];
				else
					gp+=gc[i]+jc[i];
			u++,g+=(jp<gp);
		}while(next_permutation(gc,gc+9));
		printf("%.5lf %.5lf\n",g/u,1-g/u);
	}
	return 0;
}



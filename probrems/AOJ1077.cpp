#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	while(1){
		int n[6];
		int p[3];
		for(int i=0;i<6;i++)
			scanf("%d",n+i);
		p[0]=n[0]+n[3];
		p[1]=n[1]+n[4];
		p[2]=n[2]+n[5];
		if(!p[0] && !p[1] && !p[2])
			break;
		int ans=0;
		for(int c=0;c<=3;c++)
			if(c<=p[0] && c<=p[1] && c<=p[2])
				ans=max(ans,(p[0]-c)/3+(p[1]-c)/3+(p[2]-c)/3+c);
		printf("%d\n",ans);
	}
	return 0;
}


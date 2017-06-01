#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	for(int time=1;;time++)
	{
		int p,e,i,d;
		scanf("%d%d%d%d",&p,&e,&i,&d);
		if(p==e && e==i && i==d && d==-1)
			break;
		p%=23,e%=28,i%=33;
		for(p;;p+=23)
			if(d<p && (p-e)%28==0 && (p-i)%33==0)
			{
				printf("Case %d: the next triple peak occurs in %d days.\n",time,p-d);
				break;
			}
		fflush(stdout);
	}
	return 0;
}


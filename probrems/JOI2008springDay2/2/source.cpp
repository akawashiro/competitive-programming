#include <stdio.h>
#include <algorithm>

using namespace std;
typedef long long LL;

int nWrong;
LL xWrong[100000+10];
LL yWrong[100000+10];

int check(LL d)
{
	int need=0,bef;
	for(int i=0;i<nWrong;)
	{
		need++;
		bef=xWrong[i];
		while(i<nWrong && xWrong[i]<=bef+d)
			i++;
	}
	for(int i=0;i<nWrong;)
	{
		need++;
		bef=yWrong[i];
		while(i<nWrong && yWrong[i]<=bef+d)
			i++;
	}
	return need;
}

int main()
{
	int nMachine;
	scanf("%d%d",&nMachine,&nWrong);
	for(int i=0;i<nWrong;i++)
		scanf("%lld%lld",xWrong+i,yWrong+i);
	sort(xWrong,xWrong+nWrong);
	sort(yWrong,yWrong+nWrong);
	LL bo=0,ce=1000000000;
	while(1<ce-bo)
	{
		LL mi=(bo+ce)/2;
		//printf("mi=%lld\n",mi);
		//printf("check(%lld)=%d\n",mi,check(mi));
		if(check(mi)<=nMachine)
			ce=mi;
		else
			bo=mi;
	}
	if(check(bo)<=nMachine)
		printf("%lld\n",bo);
	else
		printf("%lld\n",ce);
	return 0;
}



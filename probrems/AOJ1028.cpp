#include <algorithm>
#include <stdio.h>

using namespace std;

int needNum(int pay,int n1,int n5,int n10,int n50,int n100,int n500)
{
	int r=0;
	if(pay<n500*500)
	{
		r+=pay/500;
		pay%=500;
	}
	else
	{
		r+=n500;
		pay-=n500*500;
	}
	if(pay<n100*100)
	{
		r+=pay/100;
		pay%=100;
	}
	else
	{
		r+=n100;
		pay-=n100*100;
	}
	if(pay<n50*50)
	{
		r+=pay/50;
		pay%=50;
	}
	else
	{
		r+=n50;
		pay-=n50*50;
	}
	if(pay<n10*10)
	{
		r+=pay/10;
		pay%=10;
	}
	else
	{
		r+=n10;
		pay-=n10*10;
	}
	if(pay<n5*5)
	{
		r+=pay/5;
		pay%=5;
	}
	else
	{
		r+=n5;
		pay-=n5*5;
	}
	if(pay<n1*1)
	{
		r+=pay/1;
		pay%=1;
	}
	else
	{
		r+=n1;
		pay-=n1*1;
	}
	return (0<pay)?10*1000:r;
}

int main()
{
	while(1)
	{
		int P,n1,n5,n10,n50,n100,n500,ans=10*1000;
		scanf("%d",&P);
		if(P==0)
			break;
		scanf("%d%d%d%d%d%d",&n1,&n5,&n10,&n50,&n100,&n500);
		for(int i=P;i<=P*2;i++)
			ans=min(ans,needNum(i,n1,n5,n10,n50,n100,n500)+needNum(i-P,1000,1000,1000,1000,1000,1000));
		printf("%d\n",ans);
	}
	return 0;
}


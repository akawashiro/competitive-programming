#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
typedef long long LL;

int nex[1<<24];
int n2i[1<<24];
int seq[1<<24];

int main()
{
	int pos=0;
	LL m,p,q,pSum=0,qSum=0;
	cin>>m>>p>>q;
	p--;
	for(int i=0;i<m;i++)
	{
		int a;
		cin>>a;
		pos=pos*2+a%2;
		if(0<p)
		{
			p--;
			pSum+=a%2;
		}
		if(0<q)
		{
			q--;
			qSum+=a%2;
		}
		//printf/g("%d ",a%2);
	}
	//printf/g("| ");
	int beginLoop,endLoop;
	memset(nex,-1,sizeof(nex));
	for(int i=0;nex[pos]==-1;i++)
	{
		int n=((pos<<1)&((1<<m)-1)) + ((pos>>(m-1))+pos%2)%2;
		seq[i]=n%2;
		//printf/g("%d ",n%2);
		nex[pos]=n;
		n2i[pos]=i;
		if(nex[n]!=-1)
		{
			beginLoop=n2i[nex[pos]];
			endLoop=i;
		}
		pos=n;
	}
	//printf/g("\n");
	int loopSum=0;
	for(int i=beginLoop;i<=endLoop;i++)
		loopSum+=seq[i];

	//printf/g("beginLoop=%d endLoop=%d loopSum=%d \n",beginLoop,endLoop,loopSum);
	//printf/g("p=%lld pSum=%lld q=%lld qSum=%lld \n",p,pSum,q,qSum);

	for(int i=0;i<beginLoop && 0<p;i++,p--)
		pSum+=seq[i];
	pSum+=p/(LL)(endLoop-beginLoop+1)*(LL)loopSum;
	p%=(endLoop-beginLoop+1);
	for(int i=beginLoop;0<p;p--,i++)
		pSum+=seq[i];

	//printf/g("p=%lld pSum=%lld q=%lld qSum=%lld \n",p,pSum,q,qSum);

	for(int i=0;i<beginLoop && 0<q;i++,q--)
		qSum+=seq[i];
	qSum+=q/(LL)(endLoop-beginLoop+1)*(LL)loopSum;
	q%=(endLoop-beginLoop+1);
	for(int i=beginLoop;0<q;q--,i++)
		qSum+=seq[i];

	//printf/g("p=%lld pSum=%lld q=%lld qSum=%lld \n",p,pSum,q,qSum);

	cout<<qSum-pSum<<endl;
	return 0;
}


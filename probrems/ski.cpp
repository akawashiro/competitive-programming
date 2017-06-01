#include <stdio.h>
#include <vector>
#include <string.h>
#include <float.h>

using namespace std;

int n;
double vAve;
double cache[10000+10];
int isStart[10000+10];
int isUsed[10000+10];
vector<int> vG[10000+10];
vector<int> eG[10000+10];
vector<int> dG[10000+10];

double rec(int pos)
{
	if(isStart[pos])
		return 0.0;
	else if(isUsed[pos])
		return cache[pos];
	else
	{
		double r=DBL_MAX;
		for(int i=0;i<(int)vG[pos].size();i++)
			r=min(r,(1.0-vAve/vG[pos][i])*dG[pos][i]+rec(eG[pos][i]));
		isUsed[pos]=1;
		return cache[pos]=r;
	}
}

double check(double v)
{
	memset(isUsed,0,sizeof(isUsed));
	vAve=v;
	return rec(n-1);
}

int main()
{
	{
		int m,c;
		scanf("%d%d%d",&n,&m,&c);
		for(int i=0;i<m;i++)
		{
			int a;
			scanf("%d",&a);
			isStart[a-1]=1;
		}
		for(int i=0;i<c;i++)
		{
			int f,t,d,s;
			scanf("%d%d%d%d",&f,&t,&d,&s);
			f--,t--;
			eG[t].push_back(f);
			vG[t].push_back(s);
			dG[t].push_back(d);
		}
	}

	double ceil=1000000,bottom=0;
	for(int i=0;i<100;i++)
	{
		double mi=(ceil+bottom)/2;
		if(0<check(mi))	//fail
			bottom=mi;
		else
			ceil=mi;
	}
	printf("bottom=%lf ceil=%lf\n",bottom,ceil);
	if(check(bottom)<=0)
		printf("%.0lf\n",bottom);
	else
		printf("%.0lf\n",ceil);
	return 0;
}


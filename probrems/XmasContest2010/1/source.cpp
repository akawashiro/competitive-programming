#include <cstdio>
#include <utility>
#include <iostream>
using namespace std;

int abs(int a)
{
	return (a<0) ? -1*a : a;
}

pair<int,int> trees(int a,int b,int c,int d)
{
	int maxTree=0;
	int e=c+d;
	maxTree+=(e/(a+b))*2;
	e%=(a+b);
	if(min(a,b)<=e)
		maxTree+=2;
	else
		maxTree+=1;

	int minTree=0;
	int f=abs(c-d);
	if(f==0)
		f=c+d;
	minTree+=(f/(a+b))*2;
	f%=(a+b);
	if(f<max(a,b))
		;
	else
		minTree+=1;

	return make_pair(minTree,maxTree);
}

int main()
{
	while(1)
	{
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		if(a==0 && b==0 && c==0 && d==0)
			break;
		pair<int,int> p=trees(a,b,c,d);
		printf("%d %d\n",p.first,p.second);
	}
	return 0;
}


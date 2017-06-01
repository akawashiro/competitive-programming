#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>

using namespace std;

int main()
{
	int L[10];
	while(scanf("%d",L)!=EOF)
	{
		double r=0;
		int v1,v2;
		for(int i=1;i<10;i++)
		{
			scanf(",%d",L+i);
		}
		for(int i=0;i<10;i++)
		{
			//cout<<L[i]<<endl;
			r+=L[i];
		}
		scanf(",%d,%d",&v1,&v2);
		r=r*v1/(v1+v2);
		int ans=0;
		while(0<r)
			r-=L[ans++];
		cout<<ans<<endl;
	}
	return 0;
}

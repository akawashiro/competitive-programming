#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	double a0;
	while(cin>>a0)
	{
		double sum=0;
		for(int i=0;i<10;i++)
		{
			sum+=a0;
			a0=(i%2==0)?a0*(double)2.0:a0/(double)3;
		}
		printf("%.8lf\n",sum);
	}
	return 0;
}

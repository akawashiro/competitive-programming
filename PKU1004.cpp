#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	double sum=0;
	for(int i=0;i<12;i++)
	{
		double f;
		cin >> f;
		sum+=f;
	}
	sum/=12.0;
	sum = ((int)(sum*100.0+0.5))/100.0;
	printf("$%.2lf\n",sum);
	return 0;
}


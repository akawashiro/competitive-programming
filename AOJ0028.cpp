#include <iostream>

using namespace std;

int main()
{
	int val[100+10];
	for(int i=0;i<100+10;i++)
		val[i]=0;
	int most=0;
	int a;
	while(cin>>a)
	{
		val[a]++;
		most=max(most,val[a]);
	}
	for(int i=0;i<100+10;i++)
		if(val[i]==most)
			cout<<i<<endl;
	return 0;
}


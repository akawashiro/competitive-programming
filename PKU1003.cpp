#include <iostream>
using namespace std;

int main()
{
	double len;
	cin >> len;
	while(len!=0.0)
	{
		int n;
		double d=0.0;
		for(n=1;d<len;n++)
			d+=1.0/(n+1);
		cout << n-1 << " card(s)" << endl;
		cin >> len;
	}
	return 0;
}


#include <iostream>
using namespace std;

int main()
{
	long long a,b=1;
	cin >> a;
	if(a==0)
		cout << 1 << endl;
	else
	{
		for(a;0<a;a--)
			b*=a;
		cout << b << endl;
	}
	return 0;
}


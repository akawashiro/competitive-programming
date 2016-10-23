#include <iostream>

using namespace std;
typedef long long LL;

int main()
{
	LL k,l;
	cin>>k>>l;
	for(LL i=k,imp=0;i<=l;i*=k,imp++)
	{
		if(i==l)
		{
			cout<<"YES"<<endl<<imp<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}


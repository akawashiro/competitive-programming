#include <iostream>

using namespace std;
typedef long long LL;

int main()
{
	while(1)
	{
		LL n;
		int ans=0;
		cin>>n;
		if(n==0)
			break;
		for(LL i=5;i<=n;i*=5)
			ans+=n/i;
		cout<<ans<<endl;
	}
	return 0;
}


#include <iostream>

using namespace std;

typedef long long LL;

int main()
{
	LL n,x,y;
	cin>>n>>x>>y;
	LL last=y-n+1;
	if(n<=y && x<=n-1+last*last && n-1+last<=y)
	{
		for(int i=0;i<n-1;i++)
			cout<<1<<endl;
		cout<<last<<endl;
		return 0;
	}
	cout<<-1<<endl;
	return 0;
}


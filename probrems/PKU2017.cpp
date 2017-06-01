#include <iostream>

using namespace std;

int main()
{
	int n;
	while(1)
	{
		cin>>n;
		if(n==-1)
			break;
		int r=0,b=0;
		for(int i=0;i<n;i++)
		{
			int a,c;
			cin>>a>>c;
			r+=a*(c-b);
			b=c;
		}
		cout<<r<<" miles"<<endl;
	}
}


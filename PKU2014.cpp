#include <iostream>

using namespace std;

int main()
{
	int m;
	while(1)
	{
		cin>>m;
		if(m==0)
			break;
		int width=0,height=0,w=0,h=0;
		while(1)
		{
			int a,b;
			cin>>a>>b;
			if(a==-1 && b==-1)
			{
				width=max(width,w);
				height+=h;
				break;
			}
			else if(m<a+w)
			{
				width=max(width,w);
				height+=h;
				w=a,h=b;
			}
			else
			{
				w+=a;
				h=max(h,b);
			}
		}
		cout<<width<<" x "<<height<<endl;
	}
	return 0;
}


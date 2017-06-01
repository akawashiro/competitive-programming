#include <iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int test=0;test<n;test++)
	{
		int S,H;
		int hatches[60][2];
		cin>>S>>H;
		for(int i=0;i<H;i++)
			cin>>hatches[i][0]>>hatches[i][1];
		int poodle=1;
		for(int x=0;x<=S;x++)
			for(int y=0;y<=S;y++)
			{
				int i;
				for(i=0;i<H;i++)
					if(hatches[i][0]==x && hatches[i][1]==y)
						break;
				if(i!=H)
					continue;
				int m=min(min(x,S-x),min(y,S-y));
				for(i=0;i<H;i++)
				{
					int xd=hatches[i][0]-x;
					int yd=hatches[i][1]-y;
					int d=xd*xd+yd*yd;
					if(m*m<d)
						break;
				}
				if(i==H)
				{
					cout<<x<<" "<<y<<endl;
					poodle=0;
					x=S,y=S;
				}
			}
		if(poodle)
			cout<<"poodle"<<endl;
	}
	return 0;
}

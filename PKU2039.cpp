#include <iostream>
#include <string>

using namespace std;

char ar[25][200];

int main()
{
	int n;
	while(1)
	{
		cin>>n;
		if(n==0)
			break;
		string so;
		cin>>so;
		for(int i=0;i<so.size();i++)
		{
			int y=i/n;
			int x=(y%2==0)?(i%n):(n-i%n-1);
			ar[y][x]=so[i];
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<so.size()/n;j++)
				cout<<ar[j][i];
		cout<<endl;
	}
	return 0;
}


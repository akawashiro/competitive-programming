#include <iostream>
#include <string>
#include <vector>
using namespace std;

void calc(int N)
{
	vector<string> treasure(21,string(21,'N'));
	int x,y,i,j,M,r;
	for(i=0;i<N;i++)
	{
		cin >> x >> y;
		treasure[x][y]='T';
	}

	cin >> M;
	x=10,y=10;
	for(i=0;i<M;i++)
	{
		char dir;
		int dif;
		cin >> dir >> dif;
		int mx=0,my=0;
		if(dir=='N')
			my=1;
		if(dir=='S')
			my=-1;
		if(dir=='E')
			mx=1;
		if(dir=='W')
			mx=-1;
		for(j=0;j<dif;j++)
		{
			x+=mx;
			y+=my;
			treasure[x][y]='S';
		}
	}

	r=0;
	for(x=0;x<=20;x++)
		for(y=0;y<=20;y++)
			if(treasure[x][y]=='T')
				r++;

	if(r==0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

int main()
{
	int N;
	cin >> N;
	while(N!=0)
	{
		calc(N);
		cin >> N;
	}
	return 0;
}


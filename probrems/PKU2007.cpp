#include <iostream>
#include <vector>
#include <algorithm>
#include <float.h>
#include <math.h>

using namespace std;

vector<pair<double,pair<int,int> > > quad1,quad2,quad3,quad4;

void show1()
{
	for(int i=0;i<(int)quad1.size();i++)
		cout<<"("<<quad1[i].second.first<<","<<quad1[i].second.second<<")"<<endl;
}

void show2()
{
	for(int i=0;i<(int)quad2.size();i++)
		cout<<"("<<quad2[i].second.first<<","<<quad2[i].second.second<<")"<<endl;
}

void show3()
{
	for(int i=0;i<(int)quad3.size();i++)
		cout<<"("<<quad3[i].second.first<<","<<quad3[i].second.second<<")"<<endl;
}

void show4()
{
	for(int i=0;i<(int)quad4.size();i++)
		cout<<"("<<quad4[i].second.first<<","<<quad4[i].second.second<<")"<<endl;
}

int main()
{
	while(1)
	{
		int x,y;
		if(!(cin>>x>>y))
			break;
		if(0<x && 0<y)
		{
				quad1.push_back(make_pair((double)y/(double)x,make_pair(x,y)));
		}
		else if(x<0 && 0<y)
		{
				quad2.push_back(make_pair((double)y/(double)x,make_pair(x,y)));
		}
		else if(x<0 && y<0)
		{
				quad3.push_back(make_pair((double)y/(double)x,make_pair(x,y)));
		}
		else if(0<x && y<0)
		{
				quad4.push_back(make_pair((double)y/(double)x,make_pair(x,y)));
		}
	}
	cout<<"(0,0)"<<endl;
	sort(quad1.begin(),quad1.end());
	sort(quad2.begin(),quad2.end());
	sort(quad3.begin(),quad3.end());
	sort(quad4.begin(),quad4.end());
	if(quad1.size()==0)
	{
		show2();show3();show4();
	}
	else if(quad2.size()==0)
	{
		show3();show4();show1();
	}
	else if(quad3.size()==0)
	{
		show4();show1();show2();
	}
	else
	{
		show1();show2();show3();
	}
	return 0;
}


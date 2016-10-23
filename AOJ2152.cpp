#include <set>
#include <map>
#include <list>
#include <cmath>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;
typedef long long LL;

class CLS
{
	public:
		int pos,type;
};

int N;

void solve()
{
	CLS cls;
	list<CLS> fs;
	list<CLS>::iterator itr,jtr;

	cls.pos=0,cls.type=-1;
	fs.push_back(cls);
	cls.pos=1000000001,cls.type=-1;
	fs.push_back(cls);

	for(int time=0;time<N;time++)
	{
		char command;
		cin >> command;
		if(command=='W')
		{
			int t,l;
			cin >> t >> l;
			itr=fs.begin();
			while(0<l)
			{
				if((*itr).type==-1)
				{
					jtr=itr;
					jtr++;
					if((*jtr).pos-(*itr).pos<=l)
					{
						(*itr).type=t;
						l-=(*jtr).pos-(*itr).pos;
					}
					else
					{
						cls.type=t,cls.pos=(*itr).pos;
						(*itr).pos+=l;
						fs.insert(itr,cls);
						l=0;
					}
				}
				itr++;
			}
		}
		else if(command=='D')
		{
			int t;
			cin >> t;
			for(itr=fs.begin();itr!=fs.end();itr++)
				if((*itr).type==t)
					(*itr).type=-1;
		}
		else if(command=='R')
		{
			int p;
			cin >> p;
			itr=fs.begin(),jtr=itr,jtr++;
			while(!((*itr).pos<=p && p<(*jtr).pos))
				itr++,jtr++;
			cout << (*itr).type << endl;
		}
	}

	cout << endl;
}

int main()
{
	while(1)
	{
		cin >> N;
		if(N==0)
			break;
		solve();
	}
	return 0;
}


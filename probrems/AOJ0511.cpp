#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	bool isOK[31];
	memset(isOK,false,sizeof(isOK));
	isOK[0]=true;
	for(int i=0;i<28;i++)
	{
		int a;
		cin >> a;
		isOK[a]=true;
	}


	int y1=-1,y2;

	for(int i=0;i<31;i++)
		if(!isOK[i])
		{
			if(y1==-1)
				y1=i;
			else
				y2=i;
		}

	cout << y1 << endl << y2 << endl;

	return 0;

}


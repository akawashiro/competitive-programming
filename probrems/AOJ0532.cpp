#include <set>
#include <map>
#include <cmath>
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
typedef long long LL;

int main()
{
	for(int i=0;i<3;i++)
	{
		int a=0,b=0,c;
		cin >> c;
		a+=c*3600;
		cin >> c;
		a+=c*60;
		cin >> c;
		a+=c;

		cin >> c;
		b+=c*3600;
		cin >> c;
		b+=c*60;
		cin >> c;
		b+=c;

		c=b-a;

		cout << c/3600 << " ";
		c%=3600;
		cout << c/60 << " ";
		c%=60;
		cout << c << endl;
	}
}


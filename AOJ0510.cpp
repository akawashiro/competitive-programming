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
	int A=0,B=0;
	for(int i=0;i<4;i++)
	{
		int a;
		cin >> a;
		A+=a;
	}
	for(int i=0;i<4;i++)
	{
		int b;
		cin >> b;
		B+=b;
	}

	cout << max(A,B) << endl;
}


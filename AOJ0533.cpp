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
	vector<int> W(10),K(10);

	for(int i=0;i<10;i++)
		cin >> W[i];
	for(int i=0;i<10;i++)
		cin >> K[i];

	sort(W.begin(),W.end(),greater<int>());
	sort(K.begin(),K.end(),greater<int>());

	cout << W[0]+W[1]+W[2] << " " << K[0]+K[1]+K[2] << endl;
}


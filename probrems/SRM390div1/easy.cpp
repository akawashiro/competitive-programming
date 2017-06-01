#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

typedef long long LL;

using namespace std;

class ConcatenateNumber
{
	public:
		int getSmallest(int number, int k)
		{
			set<LL> se;
			LL p=1;
			while(p<number)
				p*=10;

			LL mod=number%k;
			LL ans=1;
			while(mod!=0)
			{
				s.insert


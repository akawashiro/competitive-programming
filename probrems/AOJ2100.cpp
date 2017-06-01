#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <utility>
using namespace std;

pair<int,int> solve(int n)
{
	int pre,next;
	int up=0,down=0;

	cin>>pre;
	for(int i=0;i<n-1;i++)
	{
		cin>>next;
		int dif=next-pre;
		if(up<dif)
			up=dif;
		if(dif<down)
			down=dif;
		pre=next;
	}
	return make_pair(up,down);
}

int main()
{
	int t;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin >> n;
		pair<int,int> r=solve(n);
		cout << r.first << " " << -1*r.second << endl;
	}
	return 0;
}


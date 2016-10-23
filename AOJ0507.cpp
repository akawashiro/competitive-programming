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

void DFS(vector<int> history,int left)
{
	if(left==0)
	{
		for(int i=0;i<history.size();i++)
		{
			if(0<i)
				cout << " ";
			cout << history[i];
		}
		cout << endl;
	}

	if(history.size()==0)
	{
		for(int i=0;0<=left-i;i++)
		{
			vector<int> v;
			v.push_back(left-i);
			DFS(v,i);
		}
	}
	else
	{
		for(int i=history.back();0<i;i--)
		{
			if(left-i<0)
				continue;
			vector<int> v=history;
			v.push_back(i);
			DFS(v,left-i);
		}
	}
}

int main()
{
	int n;
	while(1)
	{
		cin >> n;
		if(n==0)
			break;
		vector<int> v;
		DFS(v,n);
	}
	return 0;
}


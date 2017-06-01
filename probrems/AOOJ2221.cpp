#include <set>
#include <map>
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

int cache[5][5][5][5][5][5];
vector<vector<int> > input;

int calc(vector<int> v)
{
	int r=0;
	for(int i=0;i<5;i++)
	{
		if(v[i]==2)	r+=60;
		if(v[i]==3)	r+=70;
		if(v[i]==4)	r+=80;
	}
	return r;
}

vector<int> change(vector<int> _source,vector<int> clic)
{
	vector<int> source=_source;
	if(source[0]!=0)	source[0]=(source[0]+clic[0]-1)%4+1;
	if(source[1]!=0)	source[1]=(source[1]+clic[0]+clic[1]-1)%4+1;
	if(source[2]!=0)	source[2]=(source[2]+clic[1]+clic[2]-1)%4+1;
	if(source[3]!=0)	source[3]=(source[3]+clic[2]+clic[3]-1)%4+1;
	if(source[4]!=0)	source[4]=(source[4]+clic[3]-1)%4+1;

	return source;
}

int rec(int row,vector<int> up)
{
	int *p=&cache[row][up[0]][up[1]][up[2]][up[3]][up[4]];

	if(*p!=-1)
		return *p;
	if(row==4)
		return *p=calc(up);

	int r=0;
	vector<int> clic(4);
	vector<int> down=input[row+1];

	for(clic[0]=0;clic[0]<4;clic[0]++)
	for(clic[1]=0;clic[1]<4;clic[1]++)
	for(clic[2]=0;clic[2]<4;clic[2]++)
	for(clic[3]=0;clic[3]<4;clic[3]++)
	{
		vector<int> u=change(up,clic);
		vector<int> d=change(down,clic);
		int a=calc(u);
		r=max(r,a+rec(row+1,d));
	}

	return *p=r;
}

void solve()
{
	memset(cache,-1,sizeof(cache));
	input.clear();

	for(int i=0;i<5;i++)
	{
		vector<int> v;
		for(int j=0;j<5;j++)
		{
			int a;
			cin >> a;
			v.push_back(a);
		}
		input.push_back(v);
	}

	int ans=rec(0,input[0]);
	cout << ans << endl;
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		solve();
	return 0;
}


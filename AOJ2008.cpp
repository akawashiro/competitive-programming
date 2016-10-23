#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int n,hx,hy,dx,dy;
vector<double> limitTime;
vector<pair<int,int> > cPos;

double cost(int x1,int y1,int x2,int y2)
{
	double a=abs(x1-x2);
	double b=abs(y1-y2);
	return sqrt(a*a+b*b);
}

bool DFS(vector<int> isVisited,double time,int x,int y)
{
	int i;

	if(count(isVisited.begin(),isVisited.end(),true) == n)
		return true;

	for(i=0;i<n;i++)
		if(!isVisited[i] && limitTime[i] < time+cost(x,y,cPos[i].first,cPos[i].second))
			return false;

	for(i=0;i<n;i++)
	{
		if(!isVisited[i] && time+cost(x,y,cPos[i].first,cPos[i].second) < limitTime[i])
		{
			isVisited[i]=true;
			if(DFS(isVisited,time+cost(x,y,cPos[i].first,cPos[i].second),cPos[i].first,cPos[i].second))
				return true;
			isVisited[i]=false;
		}
	}
	return false;
}


void solve()
{
	limitTime.clear();
	cPos.clear();

	for(int i=0;i<n;i++)
	{
		int x,y;
		cin >> x >> y;

		cPos.push_back(make_pair(x,y));
		limitTime.push_back(cost(dx,dy,x,y));
	}

	vector<int> isVisited(n,false);
	if(DFS(isVisited,0.0,hx,hy))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int main()
{
	while(1)
	{
		cin >> n  >> hx >> hy >> dx >> dy;
		if(n==0 && hx==0 && hy==0 && dx==0 && dy==0)
			break;
		solve();
	}
	return 0;
}


#include <algorithm>
#include <vector>
#include <iostream>
#include <utility>
#include <cstdio>

typedef long long LL;
using namespace std;

LL ABS(LL num)
{
	return (num<0) ? -num : num;
}

int main()
{
	int W,H,N;
	cin >> W >> H >> N;

	vector<LL> xPos;
	vector<LL> yPos;
	vector<pair<LL,LL> > house;

	for(int i=0;i<N;i++)
	{
		LL x,y;
		cin >> x >> y;
		xPos.push_back(x);
		yPos.push_back(y);
		house.push_back(make_pair(x,y));
	}
	sort(xPos.begin(),xPos.end());
	xPos.erase(unique(xPos.begin(),xPos.end()),xPos.end());
	sort(yPos.begin(),yPos.end());
	yPos.erase(unique(yPos.begin(),yPos.end()),yPos.end());

	//printf("xPos.size()=%d yPos.size()=%d\n",xPos.size(),yPos.size());

	vector<LL> xCord;
	vector<LL> yCord;

	xCord.push_back(xPos[xPos.size()/2]);
	if(xPos.size()%2==0)
		xCord.push_back(xPos[xPos.size()/2-1]);
	yCord.push_back(yPos[yPos.size()/2]);
	if(yPos.size()%2==0)
		yCord.push_back(yPos[yPos.size()/2-1]);
	sort(xCord.begin(),xCord.end());
	sort(yCord.begin(),yCord.end());

	LL ansX=0;
	LL ansY=0;
	LL ansDist=((LL)1<<50);

	for(int i=0;i<(int)xCord.size();i++)
		for(int j=0;j<(int)yCord.size();j++)
		{
			LL x=xCord[i];
			LL y=yCord[j];
			LL maxD=0;
			LL dist=0;

			//printf("x=%lld y=%lld\n",x,y);

			for(int k=0;k<(int)house.size();k++)
			{
				LL d=ABS(house[k].first-x)+ABS(house[k].second-y);
				maxD=max(d,maxD);
				dist+=d*2;
			}
			dist-=maxD;
			if(dist<ansDist)
			{
				ansDist=dist;
				ansX=x;
				ansY=y;
			}
		}

	cout << ansDist << endl;
	cout << ansX << " " << ansY << endl;

	return 0;
}


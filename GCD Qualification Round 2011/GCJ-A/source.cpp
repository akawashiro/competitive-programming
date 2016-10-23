#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

int ABS(int n)
{
	return (n<0)?-n:n;
}

void solve(int pnum)
{
	int n;
	vector<int> bP,oP;
	vector<char> order;

	cin >> n;
	for(int i=0;i<n;i++)
	{
		char c;
		int a;
		cin >> c >> a;
		if(c=='B')
		{
			order.push_back(c);
			bP.push_back(a);
		}
		else
		{
			order.push_back(c);
			oP.push_back(a);
		}
	}

	int time=0,curTask,b=1,o=1,bc=0,oc=0;
	for(curTask=0;curTask<n;curTask++)
	{
		if(order[curTask]=='B')
		{
			int tmp=1+ABS(b-bP[bc]);
			b=bP[bc];
			bc++;
			time+=tmp;

			//printf("b-tmp=%d\n",tmp);
			
			if(oP.size()!=oc)
			{
				int t=min(ABS(o-oP[oc]),tmp);
				o+=(o<oP[oc])?t:-t;
			}
		}
		else
		{
			int tmp=1+ABS(o-oP[oc]);
			o=oP[oc];
			oc++;
			time+=tmp;

			//printf("o-tmp=%d\n",tmp);
			
			if(bP.size()!=bc)
			{
				int t=min(ABS(b-bP[bc]),tmp);
				b+=(b<bP[bc])?t:-t;
			}
		}
	}
	printf("Case #%d: %d\n",pnum,time);
	return;
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		solve(i+1);
	return 0;
}


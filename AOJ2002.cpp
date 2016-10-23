#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct RANGE
{
	int ceil,bottom,left,right;
};

bool isRectangle(vector<string> vs,RANGE ra,char c)
{
	for(int y=ra.bottom;y<=ra.ceil;y++)
		for(int x=ra.left;x<=ra.right;x++)
			if(vs[y][x]!=c && vs[y][x]!='*')
				return false;
	return true;
}

void check()
{
	int H,W;
	cin >> H >> W;

	vector<string> scan(H);
	for(int i=0;i<H;i++)
		cin >> scan[i];

	RANGE range[256];
	memset(range,-1,sizeof(range));

	vector<char> order;

	for(int y=0;y<H;y++)
		for(int x=0;x<W;x++)
			if('A'<=scan[y][x] && scan[y][x]<='Z')
			{
				int c=scan[y][x];

				if(find(order.begin(),order.end(),(char)c)==order.end())
					order.push_back(c);

				if(range[c].bottom==-1 || y<range[c].bottom)
					range[c].bottom=y;
				if(range[c].left==-1 || x<range[c].left)
					range[c].left=x;
				if(range[c].ceil<y)
					range[c].ceil=y;
				if(range[c].right<x)
					range[c].right=x;
			}

	bool isOK=true;
	sort(order.begin(),order.end());

	do{
		vector<string> vs=scan;
		isOK=true;

		/*for(int i=0;i<(int)order.size();i++)
			cout << order[i];
		cout << "---";*/

		for(int i=0;i<(int)order.size();i++)
		{
			char c=order[i];
			RANGE ra=range[(int)c];

			if(!isRectangle(vs,ra,c))
			{
				isOK=false;
				//cout << c << endl;
				break;
			}

			for(int y=ra.bottom;y<=ra.ceil;y++)
				for(int x=ra.left;x<=ra.right;x++)
					vs[y][x]='*';
		}
		if(isOK)
			break;

	}while(next_permutation(order.begin(),order.end()));

	if(isOK)
		cout << "SAFE" << endl;
	else
		cout << "SUSPICIOUS" << endl;

	/*for(int i=0;i<256;i++)
		if(range[i].bottom!=-1)
		{
			cout << (char)i << " ";
			cout << range[i].left << " " << range[i].right << " ";
			cout << range[i].bottom << " " << range[i].ceil << endl;
		}

	cout << endl << "---------------------" << endl;*/
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		check();
	return 0;
}


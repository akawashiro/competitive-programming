#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int height,weigh;

int DFS(vector<string> flag)
{
	int nQues=0;
	for(int i=0;i<height;i++)
		nQues+=count(flag[i].begin(),flag[i].end(),'?');
	if(nQues==0)
	{
		for(int y=0;y<height-1;y++)
			for(int x=0;x<weigh-1;x++)
				if(flag[y][x]=='J' && flag[y][x+1]=='O' && flag[y+1][x]=='I')
					return 1;
		return 0;
	}
	else
	{
		int ans=0;
		for(int y=0;y<height;y++)
			for(int x=0;x<weigh;x++)
				if(flag[y][x]=='?')
				{
					flag[y][x]='J';
					ans+=DFS(flag);
					flag[y][x]='O';
					ans+=DFS(flag);
					flag[y][x]='I';
					ans+=DFS(flag);
					return ans%10000;
				}
	}
	return 0;
}

int main()
{
	vector<string> flag;
	cin >> height >> weigh;
	for(int i=0;i<height;i++)
	{
		string s;
		cin >> s;
		flag.push_back(s);
	}
	cout << DFS(flag)%10000;
	return 0;
}


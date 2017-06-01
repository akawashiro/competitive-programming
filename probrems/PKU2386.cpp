#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int mv[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

void solve()
{
	int h,w,ans=0;
	vector<string> field;

	cin >> h;
	cin >> w;
	for(int i=0;i<h;i++)
	{
		string s;
		cin >> s;
		field.push_back(s);
	}

	for(int sy=0;sy<h;sy++)
		for(int sx=0;sx<w;sx++)
			if(field[sy][sx]=='W')
			{
				queue<int> que;
				que.push(sy*1000+sx);
				ans++;
				while(!que.empty())
				{
					int y=que.front()/1000;
					int x=que.front()%1000;
					que.pop();
					if(0<=y && y<h && 0<=x && x<w && field[y][x]=='W')
					{
						field[y][x]='.';
						for(int i=0;i<8;i++)
						{
							int yy=y+mv[i][0];
							int xx=x+mv[i][1];
							que.push(yy*1000+xx);
						}
					}
				}
			}

	cout << ans << endl;
}

int main()
{
	solve();
	return 0;
}


#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class SolitaireChess
{
	public:

		int cost[8][8][8][8];

		int transform(vector <string> board1, vector <string> board2)
		{
			int ans=0;
			vector<pair<int,int> > knight1,knight2;

			for(int y2=0;y2<8;y2++)
				for(int x=0;x<8;x++)
					if(board2[y2][x]=='P')
					{
						int y1;
						for(y1=y2;y1<8;y1++)
							if(board1[y1][x]=='P')
								break;
						if(y1==8)
							return -1;
						else
						{
							board1[y1][x]='.';
							board2[y2][x]='.';
							ans+=y2-y1;
						}
					}

			for(int y=0;y<8;y++)
				for(int x=0;x<8;x++)
				{
					if(board1[y][x]=='N')
						knight1.push_back(make_pair(y,x));
					if(board2[y][x]=='N')
						knight2.push_back(make_pair(y,x));
					if(board2[y][x]=='P')
					{
						ans+=y;
						knight2.push_back(make_pair(y,x));
					}
				}
			if(knight1.size()!=knight2.size())
				return -1;

			memset(cost,0,sizeof(cost));
			for(int y1=0;y1<8;y1++)
				for(int x1=0;x1<8;x1++)
					for(int y2=0;y2<8;y2++)
						for(int x2=0;x2<8;x2++)
							cost[y1][x1][y2][x2]=abs(y2-y1)+abs(x2-x1);

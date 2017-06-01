#include <string>
#include <vector>
#include <cstdio>
using namespace std;

class RectangleAvoidingColoringEasy{
		public:
				int count(vector <string> board);
};

int w=0,h=0;

bool canColored(char map[10][10])
{
		for(int i=0;i<h;i++){
				for(int j=0;j<w;j++){
						//printf("i=%d j=%d\n",i,j);
						if(map[i][j]!='?'){
								for(int k=0;k<h;k++){
										if(k==i)
												continue;
										for(int l=0;l<w;l++){
												if(l==j)
														continue;
												char c=map[i][j];
												if(c==map[i][l] && c==map[k][l] && c==map[k][j])
														return false;
										}
								}
						}
				}
		}
		return true;
}

int fillMap(char map[10][10])
{
		bool isEnd=true;
		for(int i=0;i<h;i++)
				for(int j=0;j<w;j++)
						if(map[i][j]=='?')
								isEnd=false;
		if(isEnd)
				return 1;

		int r=0;
		for(int i=0;i<h;i++){
				for(int j=0;j<w;j++){
						if(map[i][j]=='?'){
								bool isCanW=true,isCanB=true;
								for(int k=0;k<h;k++){
										if(k==i)
												continue;
										for(int l=0;l<w;l++){
												if(j==l)
														continue;
												if('W'==map[i][l] && 'W'==map[k][l] && 'W'==map[k][j])
														isCanW=false;
												if('B'==map[i][l] && 'B'==map[k][l] && 'B'==map[k][j])
														isCanB=false;
										}
								}
								if(isCanW){
										map[i][j]='W';
										r+=fillMap(map);
										map[i][j]='?';
								}
								if(isCanB){
										map[i][j]='B';
										r+=fillMap(map);
										map[i][j]='?';
								}
								return r;
						}
				}
		}
		return 0;
		//return r;
}

int RectangleAvoidingColoringEasy::count(vector <string> board)
{
	h=board.size();
	w=board[0].size();
	printf("h=%d w=%d\n",h,w);
	char map[10][10];
	for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
					map[i][j]=board[i][j];
	if(!canColored(map)){
			//printf("canColored was finished\n");
			return 0;
	}
	return fillMap(map);
}


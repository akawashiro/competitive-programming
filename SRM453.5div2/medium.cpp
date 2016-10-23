#include <string>
#include <vector>
using namespace std;

class MazeMaker{
	public:
		int longestPath(vector <string> maze, int startRow, int startCol, vector <int> moveRow, vector <int> moveCol)
		{
			int width=maze[0].size(),height=maze.size(),ans=0;
			int map[50][50];
			for(int i=0;i<height;i++)
				for(int j=0;j<width;j++){
					if(maze[i][j]=='.')
						map[i][j]=-1;
					if(maze[i][j]=='X')
						map[i][j]=-2;
				}

			map[startRow][startCol]=0;
			for(int i=0;i<3000;i++)
				for(int j=0;j<height;j++)
					for(int k=0;k<width;k++)
						if(map[j][k]==i){
							for(int l=0;l<moveRow.size();l++){
								int y=j+moveRow[l];
								int x=k+moveCol[l];
								if(0<=y && y<height && 0<=x && x<width)
									if(map[y][x]==-1)
										map[y][x]=i+1;
							}
						}

			for(int i=0;i<height;i++)
				for(int j=0;j<width;j++){
					if(map[i][j]==-1)
						return -1;
					ans=max(map[i][j],ans);
				}
			return ans;
		}
};

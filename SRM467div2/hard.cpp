#include <vector>
#include <string>
using namespace std;

class MazeOnFire{
	public:
		int maximumTurns(vector <string> maze)
		{
			int h=maze.size(),w=maze[0].size();
			
			int turn=0;
			for(turn=0;turn<3000;turn++){
				bool isAlive=false;
				for(int i=0;i<h;i++)
					for(int j=0;j<w;j++)
						if(maze[i][j]=='$')
							isAlive=true;
				if(!isAlive)
					break;
				for(int i=0;i<h;i++)
					for(int j=0;j<w;j++)
						if(maze[i][j]=='$'){
							if(0<=i-1 && maze[i-1][j]=='.')	maze[i-1][j]='%';
							if(i+1<h  && maze[i+1][j]=='.')	maze[i+1][j]='%';
							if(0<=j-1 && maze[i][j-1]=='.')	maze[i][j-1]='%';
							if(j+1<w  && maze[i][j+1]=='.')	maze[i][j+1]='%';
							maze[i][j]='%';
						}
				for(int i=0;i<h;i++)
					for(int j=0;j<w;j++)
						if(maze[i][j]=='F'){
							if(0<=i-1 && maze[i-1][j]!='#' && maze[i-1][j]!='F')	maze[i-1][j]='G';
							if(i+1<h  && maze[i+1][j]!='#' && maze[i+1][j]!='F')	maze[i+1][j]='G';
							if(0<=j-1 && maze[i][j-1]!='#' && maze[i][j-1]!='F')	maze[i][j-1]='G';
							if(j+1<w  && maze[i][j+1]!='#' && maze[i][j+1]!='F')	maze[i][j+1]='G';
							maze[i][j]='G';
						}
				for(int i=0;i<h;i++)
					for(int j=0;j<w;j++){
						if(maze[i][j]=='%')
							maze[i][j]='$';
						if(maze[i][j]=='G')
							maze[i][j]='F';
					}
			}
			return (turn==3000) ? -1 : turn;
		}
};

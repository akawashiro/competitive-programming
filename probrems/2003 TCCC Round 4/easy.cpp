#include <vector>
using namespace std;

class ChessMetric{
public:
long long howMany(int size, vector <int> start, vector <int> end, int numMoves)
{
long long mapNew[size][size];
long long mapOld[size][size];
int canMove[16][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1},{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
for(int i=0;i<size;i++)	for(int j=0;j<size;j++)	{mapNew[i][j]=0; mapOld[i][j]=0;}
mapOld[start[0]][start[1]]=1;

for(int i=0;i<numMoves;i++){
for(int j=0;j<size;j++){
for(int k=0;k<size;k++){
for(int l=0;l<16;l++){
if(0<=j+canMove[l][0] && j+canMove[l][0]<size && 0<=k+canMove[l][1] && k+canMove[l][1]<size){
mapNew[j+canMove[l][0]][k+canMove[l][1]]+=mapOld[j][k];
//printf("mapNew[%d][%d]=%lld\n",j+canMove[l][0],k+canMove[l][1],mapNew[j+canMove[l][0]][k+canMove[l][1]]);
}
}
}
}
for(int j=0;j<size;j++)	for(int k=0;k<size;k++)	{mapOld[j][k]=mapNew[j][k]; mapNew[j][k]=0;	}
}
return mapOld[end[0]][end[1]];
}
};

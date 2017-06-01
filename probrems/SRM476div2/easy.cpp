#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class MatrixShiftings{
public:
int minimumShifts(vector <string> matrix, int value)
{
int m=2500;
for(int i=0;i<matrix.size();i++){
for(int j=0;j<matrix[i].size();j++){
if(matrix[i][j]=='0'+value){
int a=min((int)matrix.size()-i,i)+min((int)matrix[i].size()-j,j);
m=(a<m) ? a : m;
}
}
}
return (m==2500) ? -1 : m;
}
};

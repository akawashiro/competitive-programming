#include <vector>
#include <string>
using namespace std;

class Islands{
public:
int beachLength(vector <string> kingdom)
{
int nBeach=0;
for(int i=0;i<kingdom[0].size()-1;i++)
if(kingdom[0][i]!=kingdom[0][i+1])	nBeach++;
if(kingdom.size()==1){
return nBeach;
}else{
//if(kingdom[0][0]!=kingdom[1][0])	nBeach++;
for(int i=1;i<kingdom.size();i++){
if(i%2==1 && kingdom[i][0]!=kingdom[i-1][0]) nBeach++;
if(i%2==0 && kingdom[i][kingdom[i].size()-1]!=kingdom[i-1][kingdom[i].size()-1]) nBeach++;
for(int j=0;j<kingdom[i].size()-1;j++){
if(i%2==1){
if(kingdom[i][j]!=kingdom[i-1][j+1])	nBeach++;
if(kingdom[i][j]!=kingdom[i][j+1])		nBeach++;
if(kingdom[i-1][j+1]!=kingdom[i][j+1])	nBeach++;
}else{
if(kingdom[i][j]!=kingdom[i-1][j])		nBeach++;
if(kingdom[i][j]!=kingdom[i][j+1])		nBeach++;
if(kingdom[i][j+1]!=kingdom[i-1][j])	nBeach++;
}
}
}
return nBeach;
}
}
};

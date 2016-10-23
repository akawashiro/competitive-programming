#include <string>
using namespace std;

class ColorfulTilesEasy{
public:
int theMin(string room)
{
if(room.size()==1 || (room.size()==2 && room[0]!=room[1]))
return 0;
if(room.size()==2 && room[0]==room[1])
return 1;
int count=0;
for(int i=1;i<room.size();i++){
if(room[i-1]==room[i]){
count++;
i++;
}
}
return count;
}
};

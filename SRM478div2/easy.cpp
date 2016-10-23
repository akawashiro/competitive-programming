#include <vector>
using namespace std;

class thePouring{
public:
vector <int> thePouring(vector <int> capacities, vector <int> bottles, vector <int> fromId, vector <int> toId)
{
for(int i=0;i<fromId.size();i++){
if(capacities[toId]-botteles[toId]<bottles[fromId]){
bottles[fromId]=bottles[toId]+bottles[fromId]-capacities[toId];
bottles[toId]=capacities[toId];
}else{
bottles[toId]+=bottles[fromId];
bottles[fromId]=0;
}
}
return bottles;
}
};

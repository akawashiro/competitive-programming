#include <vector>
using namespace std;

class TheAirTripDivTwo{
public:
int find(vector <int> flights, int fuel)
{
for(int i=0;i<flights.size();i++){
if(flights[i]<=fuel)
fuel-=flights[i];
else
return i;
}
return flights.size();
}
};

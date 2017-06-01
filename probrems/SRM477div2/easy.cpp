#include <vector>
using namespace std;

class VacationTime{
public:
int bestSchedule(int N, int K, vector <int> workingDays)
{
int minMeeting=1000;
for(int i=1;i<=N-K+1;i++){
int meeting=0;
for(int j=0;j<workingDays.size();j++){
if(i<=workingDays[j] && workingDays[j]<=i+K-1)
meeting++;
}
if(meeting<minMeeting)
minMeeting=meeting;
}
return minMeeting;
}
};

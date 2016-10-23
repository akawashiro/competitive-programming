#include <vector>
#include <algorithm>
using namespace std;

class Badgers{
public:
int feedMost(vector <int> hunger, vector <int> greed, int totalFood)
{
if(hunger.size()==1)	return (totalFood<hunger[0]) ? 0 : 1;
int a=hunger[0];
for(int i=0;i<hunger.size();i++)
a=min(hunger[i],a);
if(totalFood<a)	return 0;

for(int i=0;i<=hunger.size();i++){
vector<int> both(hunger.size());
for(int j=0;j<hunger.size();j++)
both[j]=hunger[j]+greed[j]*i;
int t=totalFood;
sort(both.begin(),both.end());
for(int j=0;j<i+1;j++){
t-=both[j];
if(t<0)
return i;
}
}
return hunger.size();
}
};

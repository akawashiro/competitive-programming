#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

class FlowerGarden{
public:
vector <int> getOrdering(vector <int> height, vector <int> bloom, vector <int> wilt)
{
int n=height.size();
int tr[n][n];
vector<int> ans;

for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
if(i==j){
tr[i][j]=0;
continue;
}
if( ((bloom[i]<=bloom[j]&&bloom[j]<=wilt[i]) || (bloom[j]<=bloom[i]&&bloom[i]<=wilt[j])) && height[j]<height[i])
tr[i][j]=1;
else
tr[i][j]=0;
}
}


while(ans.size()!=n){
int index=-1;
for(int i=0;i<n;i++){
int sum=0;
for(int j=0;j<n;j++)	sum+=tr[i][j];
if(sum==0){
if(index==-1)	index=i;
else	index=(height[index]<height[i])	? i : index;
}
}
for(int i=0;i<n;i++)	tr[i][index]=0;
tr[index][index]=1;
ans.push_back(height[index]);
}

return ans;
}
};

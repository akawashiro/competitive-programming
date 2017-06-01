#include <vector>
#include <cstdio>
#include <sstream>
#include <string>
#include <utility>
using namespace std;

class AvoidRoads{
public:
long long numWays(int width, int height, vector <string> bad)
{
vector<pair<int,int> > badPoint;
for(int i=0;i<bad.size();i++){
stringstream ss(bad[i]);
int a,b,c,d;
ss>>a;	ss>>b;	ss>>c;	ss>>d;
b+=a*1000;	d+=c*1000;
badPoint.push_back(make_pair(min(b,d),max(b,d)));
}

long long route[width+1][height+1];
route[0][0]=1;
for(int i=1;i<=width;i++){
route[i][0]=route[i-1][0];
for(int j=0;j<badPoint.size();j++){
if(badPoint[j].second==i*1000 && badPoint[j].first==(i-1)*1000){
route[i][0]=0;
break;
}
}
//printf("route[%d][0]=%lld\n",i,route[i][0]);
}
for(int i=1;i<=height;i++){
route[0][i]=route[0][i-1];
for(int j=0;j<badPoint.size();j++){
if(badPoint[j].second==i && badPoint[j].first==i-1){
route[0][i]=0;
break;
}
}
//printf("route[0][%d]=%lld\n",i,route[0][i]);
}

for(int i=1;i<=width;i++){
for(int j=1;j<=height;j++){
route[i][j]=route[i-1][j]+route[i][j-1];
//route[i][j]=0;
for(int k=0;k<badPoint.size();k++){
if(badPoint[k].second==i*1000+j && badPoint[k].first==(i-1)*1000+j)
route[i][j]-=route[i-1][j];
if(badPoint[k].second==i*1000+j && badPoint[k].first==i*1000+j-1)
route[i][j]-=route[i][j-1];
}
}
}

return route[width][height];
}
};

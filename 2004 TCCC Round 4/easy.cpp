#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

class BadNeighbors{
public:
int maxDonations(vector <int> donations)
{
int n=donations.size();
if(n<=3){
int m=0;
for(int i=0;i<n;i++)	m=max(m,donations[i]);
return m;
}

int dp[n][n];
for(int i=0;i<n;i++)	dp[i][0]=donations[i];
for(int i=0;i<n;i++)	dp[i][1]=max(donations[i],donations[(i+1)%n]);
for(int i=0;i<n;i++)	dp[i][2]=max(donations[(i+1)%n],donations[i]+donations[(i+2)%n]);

for(int i=3;i<n;i++){
for(int j=0;j<n;j++){
int m=0;
m=max(donations[j]+dp[(j+2)%n][i-2],m);
m=max(donations[(j+1)%n]+dp[(j+3)%n][i-3],m);
m=max(donations[(j+i)%n]+dp[j][i-2],m);
m=max(donations[(j+i-1)%n]+dp[j][i-3],m);
dp[j][i]=m;
}
}

/*for(int i=0;i<n;i++){
for(int j=0;j<n;j++)	printf("%3d ",dp[i][j]);
printf("\n");
}*/

return max(dp[0][n-2],dp[1][n-2]);
}
};

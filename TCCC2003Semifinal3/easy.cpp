#include <vector>
using namespace std;

class ZigZag{
public:
int longestZigZag(vector<int> sequence)
{
int n=sequence.size();
if(n==1)	return 1;

int dp[n][n];
for(int i=0;i<n;i++)	for(int j=0;j<n;j++)	dp[i][j]=-1;
for(int i=0;i<n;i++)	if(sequence[i]!=sequence[0])	dp[i][0]=2;
for(int i=0;i<n;i++)	dp[i][i]=1;

for(int i=1;i<n;i++){
for(int j=i+1;j<n;j++){
int m=0;
if(sequence[i]<sequence[j]){
for(int k=0;k<=i;k++)	if(sequence[k]>sequence[i])	m=max(m,dp[i][k]);
m=(m==0) ? 1 : m;
}else if(sequence[i]>sequence[j]){
for(int k=0;k<=i;k++)	if(sequence[k]<sequence[i])	m=max(m,dp[i][k]);
m=(m==0) ? 1 : m;
}
dp[j][i]=m+1;
}
}

int r=0;
for(int i=0;i<n;i++)	r=max(r,dp[n-1][i]);

return r;
}
};

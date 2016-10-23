#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

class RandomAppleEasy{
public:
double theRed(vector <int> red, vector <int> green)
{
vector<int> sum(1001,0);
vector<int> num(1001,0);
sum[red[0]+green[0]]=red[0];	
num[red[0]+green[0]]=1;	
for(int i=1;i<red.size();i++){
				for(int j=1000;0<j;j--)
								if(sum[j]!=0){
												sum[j+red[i]+green[i]]+=(red[i]*num[j]+sum[j]);	
												num[j+red[i]+green[i]]+=num[j];	
								}
				sum[red[i]+green[i]]+=red[i];	
				num[red[i]+green[i]]+=1;	
}
for(int i=0;i<=1000;i++)
				if(sum[i]!=0)
				printf("sum[%d]=%d\n",i,sum[i]);
double ans=0;
for(int i=1000;0<i;i--)
				ans+=(double)sum[i]/(double)i;
return ans/(pow(2,red.size())-1);
}
};

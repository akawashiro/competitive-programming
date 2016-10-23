//this is copied
#include <vector>

using namespace std;

class Jewelry{
	public:
		long long howMany(vector<int>);
};

long long cn[31][31];

void init(){
	int i,j;
	for(i=0;i<31;i++)
		for(j=0;j<31;j++)
			cn[i][j]=0;
	for(i=0;i<31;i++)
		cn[i][0]=1;
	for(i=1;i<31;i++)
		for(j=1;j<31;j++)
			cn[i][j]=cn[i-1][j-1]+cn[i-1][j];
}

long long Jewelry::howMany(vector<int> val)
{
	init();
	sort(val.begin(),vel.end());
	int n=val.size();
	int i,j,k;
	long long ans=0;
	long long sum[2][30001];
	int cnt1,cnt2;
	for(i=1;i<n;i++){
		for(j=0;j<30001;j++)
			sum[0][j]=sum[1][j]=0;
		for(cnt1=1;cnt1<=i && val[i-1]==val[i-cnt1];cnt1++);
		cnt1--;
		for(cnt2=0;i+cnt2<n && val[i-1]==val[i+cnt2];cnt2++;);
		cnt2+=cnt1;

		sum[0][cnt1*val[i-1]]=cn[cnt2][cnt1];
		for(k=0;k<i-cnt1;k++)
			for(j=30000-val[k];0<=j;j--)
				sum[0][j+val[k]]+=sum[0][j];
		
		sum[1][0]=1;
		for(k=i;k<n;k++)
			for(j=30000-val[k];0<=j;j--)
				sum[1][j+val[k]]+=sum[1][j];
		
		for(j=1;j<=30000;j++)
			if(0<sum[0][j] && 0<sum[1][j])
				ans+=sum[0][j]*sum[1][j];
	}
	return ans;
}

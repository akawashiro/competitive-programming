#include <stdio.h>
#include <utility>
#include <set>

using namespace std;

int n;
int stars[1000+10][2+1];

void solve()
{
	set<pair<int,int> > pa;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&stars[i][0],&stars[i][1]);
		pa.insert(make_pair(stars[i][0],stars[i][1]));
	}
	int res=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			{
				int mx=stars[j][0]-stars[i][0];
				int my=stars[j][1]-stars[i][1];
				if(0<mx && 0<=my &&
						pa.find(make_pair(stars[i][0]-my,stars[i][1]+mx))!=pa.end() &&
						pa.find(make_pair(stars[j][0]-my,stars[j][1]+mx))!=pa.end())
					res++;
			}
	printf("%d\n",res);
}

int main()
{
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			return 0;
		solve();
	}
}


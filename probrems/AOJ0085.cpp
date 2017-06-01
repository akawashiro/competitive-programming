#include <list>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
	while(1)
	{
		int n,m,s,p;
		scanf("%d%d",&n,&m);
		if(n==0 && m==0)
			break;
		s=n,p=n-1;
		vector<int> att(n);
		for(int i=0;i<n;i++)
			att[i]=i+1;
		while(s!=1)
		{
			int t=m;
			//int t=m%s;
			while(0<t)
			{
				p=(p+1)%n;
				if(att[p]!=-1)
					t--;
			}
			//printf("%d ",att[p]);
			att[p]=-1;
			s--;
		}
		//printf("\n");
		int ans;
		for(int i=0;i<n;i++)
			if(att[i]!=-1)
				ans=att[i];
		printf("%d\n",ans);
	}
	return 0;
}


#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	while(1)
	{
		int n,m;
		vector<int> v;
		scanf("%d%d",&n,&m);
		if(n+m==0)
			break;
		for(int i=0;i<n+m;i++)
		{
			int a;
			scanf("%d",&a);
			v.push_back(a);
		}
		v.push_back(0);
		sort(v.begin(),v.end());
		int r=0;
		for(int i=0;i<n+m;i++)
			r=max(r,v[i+1]-v[i]);
		printf("%d\n",r);
	}
	return 0;
}


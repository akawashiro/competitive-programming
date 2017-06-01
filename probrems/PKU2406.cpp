#include <stdio.h>
#include <string.h>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

char str[1000000+10];

int main()
{
	while(1)
	{
		scanf("%s",str);
		if(str[0]=='.')
			break;
		//printf("%s\n",str);

		int n=strlen(str);
		vector<int> div;
		for(int i=1;i*i<=n;i++)
			if(n%i==0)
			{
				div.push_back(i);
				div.push_back(n/i);
			}
		sort(div.begin(),div.end());
		for(int i=0;i<div.size();i++)
		{
			bool b=true;
			for(int j=0;j<n && b;j+=div[i])
			{
				for(int k=0;k<div[i] && b;k++)
					if(str[k]!=str[j+k])
						b=false;
			}
			if(b)
			{
				printf("%d\n",n/div[i]);
				break;
			}
		}
	}
	return 0;
}


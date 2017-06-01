#include <stdio.h>
#include <string>

using namespace std;

int main()
{
	int time;
	scanf("%d",&time);
	for(time;0<time;time--)
	{
		int n,r;
		int ar[30],d[30];
		string s;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",ar+i);
		for(int i=0;i<n;i++)
		{
			int a=(i==0)?ar[i]:ar[i]-ar[i-1];
			for(int i=0;i<a;i++)
				s+="(";
			s+=")";
		}

		//printf("%s\n",s.c_str());

		int first=1;
		for(int i=0;i<s.size();i++)
			if(s[i]==')')
			{
				int a=1,b=1,j=i-1;
				for(j;a!=0;j--)
					if(s[j]==')')
						a++,b++;
					else
						a--;
				if(first)
				{
					first=0;
					printf("%d",b);
				}
				else
					printf(" %d",b);
			}
		printf("\n");
	}
	return 0;
}


#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;
typedef long long LL;

#define WHITE 1
#define BLACK 0

struct SEQ{int color,len;};

int n;

void solve()
{
	SEQ seq[100000];
	int pos;


	scanf("%d",&seq[0].color),seq[0].len=1;
	pos=0;

	for(int i=2;i<=n;i++)
	{

		/*for(int j=0;j<=pos;j++)
			printf("index=%d color=%d len=%d\n",j,seq[j].color,seq[j].len);
		printf("\n");*/

		int stone;
		scanf("%d",&stone);

		if((i%2)==1)
		{
			if(seq[pos].color==stone)
				seq[pos].len++;
			else
			{
				pos++;
				seq[pos].color=stone;
				seq[pos].len=1;
			}
		}
		else
		{
			if(seq[pos].color!=stone)
			{
				if(pos==0)
					seq[pos].color=stone,seq[pos].len++;
				else
				{
					seq[pos-1].len+=seq[pos].len+1;
					pos-=1;
				}
			}
			else
			{
				seq[pos].len++;
			}
		}
	}

	/*for(int j=0;j<=pos;j++)
		printf("index=%d color=%d len=%d\n",j,seq[j].color,seq[j].len);
	printf("\n");*/

	int ans=0;
	for(int i=0;i<=pos;i++)
		if(seq[i].color==0)
			ans+=seq[i].len;

	printf("%d\n",ans);
}

int main()
{
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		solve();
	}
	return 0;
}


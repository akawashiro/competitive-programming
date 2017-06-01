#include <stdio.h>
#include <string.h>

typedef long long LL;

int n;
char    stamp[1000000+100];
int cCache[2][1000000+100];
int lCache[2][1000000+100];

void rec(int isI,int pos,int &c,int &l)
{
	if(cCache[isI][pos]!=-1)
	{
		c=cCache[isI][pos];
		l=lCache[isI][pos];
		return;
	}
	else if(pos==n && isI)
	{
		c=cCache[isI][pos]=1000000+100;
		l=lCache[isI][pos]=1000000+100;
		return;
	}
	else if(pos==n)
	{
		c=cCache[isI][pos]=0;
		l=lCache[isI][pos]=0;
		return;
	}
	else
	{
		if((isI && stamp[pos]=='I')||(!isI && stamp[pos]=='O'))
		{
			int c1,c2,l1,l2;
			rec(!isI,pos+1,c1,l1);
			l1++;
			rec(isI,pos+1,c2,l2);
			c2++;
			if((LL)c1*(LL)1000000+l1<(LL)c2*(LL)1000000+l2)
				c=c1,l=l1;
			else
				c=c2,l=l2;
		}
		else
		{
			int c1,c2,l1,l2;
			rec(!isI,pos+1,c1,l1);
			c1++,l1++;
			rec(isI,pos+1,c2,l2);
			c2++;
			if((LL)c1*(LL)1000000+l1<(LL)c2*(LL)1000000+l2)
				c=c1,l=l1;
			else
				c=c2,l=l2;

		}

		cCache[isI][pos]=c;
		lCache[isI][pos]=l;
		return;
	}
}

void solve()
{
	for(int pos=n;0<=pos;pos--)
		for(int isI=0;isI<2;isI++)
		{
			if(pos==n && isI)
			{
				cCache[isI][pos]=1000000+100;
				lCache[isI][pos]=1000000+100;
			}
			else if(pos==n)
			{
				cCache[isI][pos]=0;
				lCache[isI][pos]=0;
			}
			else
			{
				int c,l;
				if((isI && stamp[pos]=='I')||(!isI && stamp[pos]=='O'))
				{
					int c1,c2,l1,l2;
					c1=cCache[!isI][pos+1];
					l1=lCache[!isI][pos+1];
					l1++;
					c2=cCache[isI][pos+1];
					l2=lCache[isI][pos+1];
					c2++;
					if((LL)c1*(LL)1000000+l1<(LL)c2*(LL)1000000+l2)
						c=c1,l=l1;
					else
						c=c2,l=l2;
				}
				else
				{
					int c1,c2,l1,l2;
					c1=cCache[!isI][pos+1];
					l1=lCache[!isI][pos+1];
					c1++,l1++;
					c2=cCache[isI][pos+1];
					l2=lCache[isI][pos+1];
					c2++;
					if((LL)c1*(LL)1000000+l1<(LL)c2*(LL)1000000+l2)
						c=c1,l=l1;
					else
						c=c2,l=l2;

				}

				cCache[isI][pos]=c;
				lCache[isI][pos]=l;
			}

		}
}

int main()
{
	scanf("%d\n",&n);
	scanf("%s",stamp);
	if(n==1 && stamp[0]=='O')
	{
		printf("1\n1\n");
		return 0;
	}
	memset(cCache,-1,sizeof(cCache));
	int c,l;
	//rec(1,0,c,l);
	solve();
	printf("%d\n%d\n",cCache[1][0],lCache[1][0]);
	return 0;
}


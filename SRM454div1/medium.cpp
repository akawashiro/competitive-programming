#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;

class NumbersAndMatches
{
	public:
		int len;
		int number[20];
		int addMatch[10][10];
		int moveMatch[10][10];
		LL cache[20][300][200];

		LL rec(int k,int leftMatch,int canMove)
		{
			LL &r=cache[k][leftMatch][canMove];
			if(r!=-1)
				;
			else if(k==len)
				return r=(leftMatch==0)?1:0;
			else
			{
				r=0;
				int now=number[k];
				for(int i=0;i<10;i++)
					if(moveMatch[now][i]<=canMove)
						r+=rec(k+1,leftMatch+addMatch[now][i],canMove-moveMatch[now][i]);
			}
			return r;
		}

		LL differentNumbers(LL N, int canMove)
		{
			char numTable[3][100]={" _     _  _     _  _  _  _  _ ",
			                       "| |  | _| _||_||_ |_   ||_||_|",
			                       "|_| _||_  _|  | _||_|  ||_| _|"};

			for(int i=0;i<10;i++)
				for(int j=0;j<10;j++)
				{
					addMatch[i][j]=0;
					moveMatch[i][j]=0;
					for(int y=0;y<3;y++)
						for(int x=0;x<3;x++)
						{
							if(numTable[y][x+i*3]!=' ')
								addMatch[i][j]++;
							if(numTable[y][x+j*3]!=' ')	
								addMatch[i][j]--;
							if(numTable[y][x+i*3]!=' ' && numTable[y][x+j*3]==' ')
								moveMatch[i][j]++;
						}
				}
			len=0;
			for(int i=0;N!=0;i++)
			{
				len++;
				number[i]=N%10;
				N/=10;
			}
			memset(cache,-1,sizeof(cache));

			return rec(0,0,canMove);
		}
};


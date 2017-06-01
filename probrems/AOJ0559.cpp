#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int DP[2][1<<20][2];

int main()
{
	int h,w;
	vector<string> flag;

	cin>>h>>w;
	for(int i=0;i<h;i++)
	{
		string s;
		cin>>s;
		flag.push_back(s);
	}
	memset(DP,0,sizeof(DP));
	DP[0][0][0]=1;
	int mask=(1<<(w-1))-1;
	for(int pos=0;pos<h*w;pos++)
	{
		memset(DP[(pos+1)%2],0,sizeof(DP[(pos+1)%2]));
		for(int state=0;state<(1<<(w-1));state++)
			for(int isLastJ=0;isLastJ<2;isLastJ++)
			{
				int y=pos/w,x=pos%w;
				DP[pos%2][state][isLastJ]%=100000;
				int now=DP[pos%2][state][isLastJ];
				if(now==0)
					continue;

				if(flag[y][x]=='J' || flag[y][x]=='?')
				{
					DP[(pos+1)%2][(state<<1)&mask][1]+=now;
					DP[(pos+1)%2][(state<<1)&mask][1]%=100000;
				}
				if(flag[y][x]=='O' || flag[y][x]=='?')
				{
					int isJO=(isLastJ && pos%w!=0);
					DP[(pos+1)%2][((state<<1)&mask)+isJO][0]+=now;
					DP[(pos+1)%2][((state<<1)&mask)+isJO][0]%=100000;
				}
				if(flag[y][x]=='I' || flag[y][x]=='?')
				{
					if(!(state & (1<<(w-2))))
						DP[(pos+1)%2][(state<<1)&mask][0]+=now;
					DP[(pos+1)%2][(state<<1)&mask][0]+=100000;
				}
			}
	}
	int nNG=0;
	for(int s=0;s<(1<<(w-1));s++)
		for(int i=0;i<2;i++)
			nNG=(nNG+DP[h*w%2][s][i])%100000;
	int U=1;
	for(int p=0;p<h*w;p++)
		if(flag[p/w][p%w]=='?')
			U=(U*3%100000);

	//printf("nNG=%d U=%d\n",nNG,U);

	cout<<(U-nNG+100000)%100000<<endl;
	return 0;
}


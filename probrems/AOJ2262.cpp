#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int h,w;
int cache[21][21][3][3][16];
vector<string> prog;

int rec(int y,int x,int my,int mx,int mem)
{
	int &res=cache[y][x][my+1][mx+1][mem];
	if(0<=res)
		return res;
	else if(res==-2)
		return 0;
	else if(res==-1)
	{
		int isQues=0;
		if(prog[y][x]=='<')			my=0,mx=-1;
		else if(prog[y][x]=='>')	my=0,mx=1;
		else if(prog[y][x]=='^')	my=-1,mx=0;
		else if(prog[y][x]=='v')	my=1,mx=0;
		else if(prog[y][x]=='_')	my=0,mx=(mem==0)?1:-1;
		else if(prog[y][x]=='|')	my=(mem==0)?1:-1,mx=0;
		else if(prog[y][x]=='?')	isQues=1;
		else if(prog[y][x]=='.')	;
		else if(prog[y][x]=='@')	return 1;
		else if('0'<=prog[y][x] && prog[y][x]<='9')	mem=prog[y][x]-'0';
		else if(prog[y][x]=='+')	mem=(mem+1)%16;
		else if(prog[y][x]=='-')	mem=(mem-1+16)%16;
		else						;

		res=-2;
		if(isQues)
		{
			int u=rec((y-1+h)%h,x,-1,0,mem);
			int d=rec((y+1)%h,x,1,0,mem);
			int l=rec(y,(x-1+w)%w,0,-1,mem);
			int r=rec(y,(x+1)%w,0,1,mem);

			res=(0<u+d+l+r)?1:0;
		}
		else
		{
			res=rec((y+my+h)%h,(x+mx+w)%w,my,mx,mem);
		}

		return res;
	}
}

int main()
{
	memset(cache,-1,sizeof(cache));
	cin>>h>>w;
	for(int i=0;i<h;i++)
	{
		string s;
		cin>>s;
		prog.push_back(s);
	}

	int ans=rec(0,0,0,1,0);
	if(ans==1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}


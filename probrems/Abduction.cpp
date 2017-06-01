#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
typedef long long LL;

int W,H,nV,nH;
int moveV[5000+10];
int moveH[5000+10];
int DP[2][1000+10];

int main()
{
	cin>>W>>H;
	W++,H++;
	{
		int n,mv;
		string input;
		cin>>n;
		cin>>input;
		if(input[0]=='L')
		{
			mv=1;
			moveH[nH]=1,nH++;
			for(int i=0;i<n;i++)
			{
				if(input[i]=='L')
					mv=(mv-1+4)%4;
				if(input[i]=='R')
					mv=(mv+1+4)%4;
				if(i%2==0)
					moveV[nV]=(mv/2==0),nV++;
				else
					moveH[nH]=(mv/2==0),nH++;
			}
		}
		else
		{
			mv=0;
			moveV[nV]=1,nV++;
			for(int i=0;i<n;i++)
			{
				if(input[i]=='L')
					mv=(mv-1+4)%4;
				if(input[i]=='R')
					mv=(mv+1+4)%4;
				if(i%2==0)
					moveH[nH]=(mv/2==0),nH++;
				else
					moveV[nV]=(mv/2==0),nV++;
			}
		}
	}
	LL ansV,ansH;
	DP[0][0]=1;
	for(int time=0;time<nV;time++)
	{
		int pre=0;
		if(moveV[time])
			for(int pos=0;pos<H;pos++)
			{
				DP[(time+1)%2][pos]+=pre;
				DP[(time+1)%2][pos]%=10000000;
				pre+=DP[time%2][pos];
				pre%=10000000;
				DP[time%2][pos]=0;
			}
		else
		{
			for(int pos=H-1;0<=pos;pos--)
			{
				DP[(time+1)%2][pos]+=pre;
				DP[(time+1)%2][pos]%=10000000;
				pre+=DP[time%2][pos];
				pre%=10000000;
				DP[time%2][pos]=0;
			}
		}
	}
	ansV=DP[nV%2][H-1];
	memset(DP,0,sizeof(DP));
	DP[0][0]=1;
	for(int time=0;time<nH;time++)
	{
		int pre=0;
		if(moveH[time])
			for(int pos=0;pos<W;pos++)
			{
				DP[(time+1)%2][pos]+=pre;
				DP[(time+1)%2][pos]%=10000000;
				pre+=DP[time%2][pos];
				pre%=10000000;
				DP[time%2][pos]=0;
			}
		else
		{
			for(int pos=W-1;0<=pos;pos--)
			{
				DP[(time+1)%2][pos]+=pre;
				DP[(time+1)%2][pos]%=10000000;
				pre+=DP[time%2][pos];
				pre%=10000000;
				DP[time%2][pos]=0;
			}
		}
	}
	ansH=DP[nH%2][W-1];
	cout<<ansV*ansH%10000000<<endl;
	return 0;
}


#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int WA[1000+10][10+10];
int  S[1000+10][10+10];
int get[1000+10][10+10];
int  P[10+10];

int main()
{
	int n,m,t,x,y;
	cin>>n>>m>>t>>x>>y;
	for(int i=1;i<=m;i++)
		cin>>P[i];
	for(int k=0;k<y;k++){
		int tk,nk,mk;
		string qk;
		cin>>tk>>nk>>mk>>qk;
		if(qk=="open")
			S[nk][mk]=tk;
		else if(qk=="correct")
			get[nk][mk]=max(P[mk]-(tk-S[nk][mk])-120*WA[nk][mk],x);
		else
			WA[nk][mk]++;
	}
	for(int i=1;i<=n;i++){
		int p=0;
		for(int j=1;j<=m;j++)
			p+=get[i][j];
		cout<<p<<endl;
	}
	return 0;
}


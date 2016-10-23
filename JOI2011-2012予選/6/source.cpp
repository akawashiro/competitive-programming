#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#define MOD 10000 
using namespace std;
int d;
int mod[1000][10];
string A,B;
int rec(int k,int s,int m,int p,int u){
	printf("rec(%d,%d,%d,%d,%d)\n",k,s,m,p,u);
	if(k==-1)	return (m==0);
	int bo=0,ce=10,uu=(u)?0:1;
	if(u)	bo=p+1;
	else 	ce=p;
	if(s==0){
		int r=0;
		for(int i=max(bo,0);i<min(ce,10);i++)
			r+=rec(k-1,0,(m+mod[k][i])%d,i,uu);
		return r%MOD;
	}else if(s==1){
		int b=A[k]-'0',r=0;
		for(int i=max(bo,b);i<min(ce,10);i++)
			if(i==b)
				r+=rec(k-1,1,(m+mod[k][b])%d,i,uu);
			else
				r+=rec(k-1,0,(m+mod[k][i])%d,i,uu);
		return r%MOD;
	}else if(s==2){
		int c=B[k]-'0'+1,r=0;
		for(int i=max(bo,0);i<min(c,ce);i++)
			if(i==c)
				r+=rec(k-1,2,(m+mod[k][c])%d,i,uu);
			else 
				r+=rec(k-1,0,(m+mod[k][i])%d,i,uu);
		return r%MOD;
	}else if(s==3){
		int b=A[k]-'0';
		int c=B[k]-'0'+1;
		int r=0;
		for(int i=max(b,bo);i<min(c,ce);i++)
			if(i==b&&i==c)
				r+=rec(k-1,3,(m+mod[k][i])%d,i,uu);
			else if(i==b)
				r+=rec(k-1,1,(m+mod[k][i])%d,i,uu);
			else if(i==c)
				r+=rec(k-1,2,(m+mod[k][i])%d,i,uu);
			else
				r+=rec(k-1,0,(m+mod[k][i])%d,i,uu);
		return r%MOD;
	}
}
int main(){
	cin>>A>>B>>d;
	for(int i=0;i<10;i++)
		mod[0][i]=i%d;
	for(int i=1;i<1000;i++)
		for(int j=0;j<10;j++)
			mod[i][j]=(mod[i-1][j]*10)%d;
	int n=B.size(),nn=A.size();
	A=string(n-A.size(),'0')+A;
	reverse(A.begin(),A.end());
	reverse(B.begin(),B.end());
	int ans=0;
	for(int l=nn;l<=n;l++)
		if(l==nn&&l==n)
			for(int i=max(1,A[n-1]-'0');i<B[n-1]-'0'+1;i++){
				int s=0,m=mod[n-1][i];
				if(A[n-1]-'0'==i)	s+=1;
				if(B[n-1]-'0'==i)	s+=2;
				ans+=rec(n-2,s,m,i,0)+rec(n-2,s,m,i,1);
			}
		else if(l==nn)
			for(int i=A[n-1]-'0';i<10;i++){
				int s=0,m=mod[n-1][i];
				if(A[n-1]-'0'==i)	s+=1;
				ans+=rec(n-2,s,m,i,0)+rec(n-2,s,m,i,1);
			}
		else if(l==n)
			for(int i=1;i<10;i++){
				int s=0,m=mod[n-1][i];
				if(A[n-1]-'0'==i)	s+=1;
				ans+=rec(n-2,s,m,i,0)+rec(n-2,s,m,i,1);
			}
	ans%=MOD;
	printf("%d\n",ans);
	return 0;
}



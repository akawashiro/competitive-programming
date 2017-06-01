#include <string>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <map>
#include <limits.h>
#define MAX_N 300000
using namespace std;
int dat[MAX_N*2];
void update(int a,int b,int k,int l,int r,int x){
	//printf("update(%d,%d,%d,%d,%d,%d)\n",a,b,k,l,r,x);
	if(r<=a||b<=l)	return;
	dat[k]=max(dat[k],x);
	if(1<r-l){
		update(a,b,k*2+1,l,(l+r)/2,x);
		update(a,b,k*2+2,(l+r)/2,r,x);
	}
}
int query(int a,int b,int k,int l,int r){
	//printf("query(%d,%d,%d,%d,%d)\n",a,b,k,l,r);
	if(r<=a||b<=l)	return INT_MIN/2;
	if(a<=l&&r<=b)	return dat[k];
	else return max(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
}
int main(){
	string s;
	cin>>s;
	int n=s.size(),a=0;
	vector<int> v;
	vector<pair<int,int> > vp;
	v.push_back(0);
	for(int i=0;i<n;i++){
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||
				s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
			a--;
		else
			a+=2;
		v.push_back(a);
		vp.push_back(make_pair(a,i));
		//printf("a=%d\n",a);
	}
	for(int i=0;i<MAX_N*2;i++)
		dat[i]=INT_MIN/2;
	vp.push_back(make_pair(0,-1));
	sort(vp.begin(),vp.end());
	int m=n+1;
	for(int i=0;i<m;i++)
		update(i,i+1,0,0,m,vp[i].second);
	int l=0;
	for(int i=0;i<m;i++){
		int a=query(i,i+1,0,0,m);
		int b=query(i+1,m,0,0,m);
		l=max(l,b-a);
		//printf("a=%d b=%d\n",a,b);
	}
	int c=0;
	for(int i=0;i+l<m;i++)
		if(0<=v[i+l]-v[i])
			c++;
	if(l!=0)
		printf("%d %d\n",l,c);
	else
		printf("No solution\n");
	return 0;
}


//AOJ0120
#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

vector<int> stringToVInt(string s)
{
	for(int i=0;i<(int)s.size();i++)
		if(!('0'<=s[i] && s[i]<='9'))
				s[i]=' ';
	stringstream ss(s);
	vector<int> res;
	int a;
	while(ss>>a)
		res.push_back(a);
	return res;
}

int n;
int r[12];
double cache[1<<12][12];
double rec(int left,int k){
	if(0<=cache[left][k])
	  return cache[left][k];
	double res=10000;
	for(int i=0;i<n;i++)
		if(i!=k&&(left&(1<<i)))
			res=min(res,rec(left&(~(1<<k)),i)+sqrt((r[k]+r[i])*(r[k]+r[i])-(r[k]-r[i])*(r[k]-r[i])));
	if(res==10000)	
		res=r[k];
	return cache[left][k]=res;
}

int main(){
	string s;
	while(getline(cin,s)){
		vector<int> v=stringToVInt(s);
		n=v.size()-1;
		for(int i=1;i<=n;i++)
			r[i-1]=v[i];
		double ans=100000;
		for(int i=0;i<n;i++){
			for(int j=0;j<(1<<n);j++)
				for(int k=0;k<n;k++)
					cache[j][k]=-1;
			ans=min(ans,r[i]+rec((1<<n)-1,i));
		}
		//printf("ans=%lf\n",ans);
		if(ans<=v[0])
			printf("OK\n");
		else
			printf("NA\n");
	}
	return 0;
}


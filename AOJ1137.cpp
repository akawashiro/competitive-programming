//AOJ1137
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(;0<T;T--){
		string s[2];
		int m,c,x,i;
		m=c=x=i=0;
		cin>>s[0]>>s[1];
		for(int j=0;j<2;j++){
			int p=s[j].size()-1;
			while(0<=p){
				char ch=s[j][p];
				p--;
				int n;
				if('0'<=s[j][p]&&s[j][p]<='9')
					n=s[j][p]-'0',p--;
				else
					n=1;
				if(ch=='m')		m+=n;
				else if(ch=='c')c+=n;	
				else if(ch=='x')x+=n;	
				else if(ch=='i')i+=n;	
			}
		}
		x+=i/10;
		c+=x/10;
		m+=c/10;
		m%=10,c%=10,x%=10,i%=10;
		if(m==0&&c==0&&x==0&&i==0)
			printf("0\n");
		else{
			if(1<m)
				printf("%d",m%10);
			if(0<m)
				printf("m");
			if(1<c)
				printf("%d",c%10);
			if(0<c)
				printf("c");
			if(1<x)
				printf("%d",x%10);
			if(0<x)
				printf("x");
			if(1<i)
				printf("%d",i%10);
			if(0<i)
				printf("i");
			printf("\n");
		}
	}
	return 0;
}


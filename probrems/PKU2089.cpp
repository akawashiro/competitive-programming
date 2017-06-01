#include <iostream>
#include <string>

using namespace std;

int c2i(string c)
{
	int r=0;
	if('1'<=c[0] && c[0]<='9')
		r+=c[0]-'1';
	else if(c[0]=='T')
		r+=9;
	else if(c[0]=='J')
		r+=10;
	else if(c[0]=='Q')
		r+=11;
	else
		r+=12;

	if(c[1]=='H')
		r+=0;
	else if(c[1]=='C')
		r+=13;
	else if(c[1]=='D')
		r+=26;
	else
		r+=39;
	return r;
}

int m2i(char c)
{
	int r=0;
	if('1'<=c && c<='9')
		r+=c-'1';
	else if(c=='T')
		r+=9;
	else if(c=='J')
		r+=10;
	else if(c=='Q')
		r+=11;
	else
		r+=12;
	return r;
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int n1,n2,n3,n4;
		string s1,s2,s3,s4;
		cin>>s1>>s2>>s3>>s4;
		n1=m2i(s1[0]);
		n2=c2i(s2);
		n3=c2i(s3);
		n4=c2i(s4);
		if(n2<n3 && n3<n4)
			n1+=1;
		else if(n2<n4 && n4<n3)
			n1+=2;
		else if(n3<n2 && n2<n4)
			n1+=3;
		else if(n4<n2 && n2<n3)
			n1+=4;
		else if(n3<n4 && n4<n2)
			n1+=5;
		else
			n1+=6;
		n1%=13;
		n1++;
		if(0<n1 && n1<10)
			cout<<n1;
		else if(n1==10)
			cout<<"T";
		else if(n1==11)
			cout<<"J";
		else if(n1==12)
			cout<<"Q";
		else
			cout<<"K";
		cout<<s1[1]<<endl;
	}
	return 0;
}


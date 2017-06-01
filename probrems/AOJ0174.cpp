//AOJ0174
#include <string>
#include <iostream>
using namespace std;
int main(){
	while(1){
		string s;
		int a=0,b=0;
		cin>>s;
		if(s=="0")
			break;
		for(int i=1;i<(int)s.size();i++)
			if(s[i]=='A')
				a++;
			else
				b++;
		if(a<b){
			if(b==11&&a<9)	a++;
			else	b++;
		}else{
			if(a==11&&b<9)	b++;
			else	a++;
		}
		//printf("%d %d\n",a,b);
		cout<<a<<" "<<b<<endl;
	}
	return 0;
}


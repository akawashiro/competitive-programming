#include <iostream>
#include <string>

using namespace std;

int main()
{
	while(1){
		string s;
		getline(cin,s);
		s+=' ';
		if(s=="END OF INPUT ")
			break;
		int a=0;
		for(int i=0;i<(int)s.size();i++){
			if(s[i]==' '){
				cout<<a;
				a=0;
			}else{
				a++;
			}
		}
		cout<<endl;
	}
	return 0;
}


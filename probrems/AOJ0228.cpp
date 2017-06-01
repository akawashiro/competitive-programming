//AOJ0228
#include <string>
#include <iostream>
using namespace std;
int main()
{
	string digit[10]={"0111111","0000110","1011011","1001111","1100110","1101101","1111101","0100111","1111111","1101111"};
	while(1){
		int n;
		string s="0000000";
		cin>>n;
		if(n==-1)
			break;
		for(int i=0;i<n;i++){
			int m;
			string t;
			cin>>m;
			for(int j=0;j<7;j++)
				t+=(s[j]==digit[m][j])?"0":"1";
			cout<<t<<endl;
			s=digit[m];
		}
	}
	return 0;
}



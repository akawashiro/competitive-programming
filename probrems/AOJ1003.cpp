//AOJ1003
#include <string>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string button[10]={" ","',.!?","abcABC","defDEF","ghiGHI","jklJKL","mnoMNO","pqrsPQRS","tuvTUV","wxyzWXYZ"};
int main(){
	while (1) {
		string input;
		if(!(cin>>input))
			break;
		int p=0;
		while(p<(int)input.size()){
			int s=-1;
			char c=input[p];
			while(input[p]==c&&p<(int)input.size())
				p++,s++;
			string str=button[c-'0'];
			if(str!=" ")
				cout<<str[s%str.size()];
			else
				cout<<string(s,' ');
		}
		cout<<endl;
	}
	return 0;
}


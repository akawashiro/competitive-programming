//AOJ0128
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
string digit[10]={"* = ****","* =* ***","* =** **","* =*** *","* =**** "," *= ****"," *=* ***"," *=** **"," *=*** *"," *=**** "};
int main(){
	int n;
	for(int t=0;scanf("%d",&n)!=EOF;t++){
		vector<string> vs;
		for(int i=0,j=10000;i<5;i++,j/=10){
			int a=n/j;
			n%=j;
			vs.push_back(digit[a]);
		}
		if(t!=0)
			printf("\n");
		for(int i=0;i<8;i++){
			for(int j=0;j<5;j++)
				printf("%c",vs[j][i]);
			printf("\n");
		}
	}
	return 0;
}


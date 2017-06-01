//AOJ0233
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
int main(){
	while(1){
		LL input;
		cin>>input;
		if(input==0)
			break;
		vector<LL> ans;
		LL p=1;
		while(input!=0){
			LL i;
			for(i=0;i<10;i++)
				if((input-i*p)%(p*10)==0)
					break;
			input-=i*p;
			ans.push_back(i);
			p*=-10;
		}
		for(int i=(int)ans.size()-1;0<=i;i--)
			cout<<ans[i];
		cout<<endl;
	}
	return 0;
}


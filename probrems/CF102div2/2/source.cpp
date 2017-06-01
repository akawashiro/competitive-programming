#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	string input,intenger,fractional,s;
	cin>>input;
	int isMinus=0;
	if(input[0]=='-'){
		isMinus=1;
		input=input.substr(1);
	}
	int p=0;
	while(p<input.size()&&input[p]!='.'){
		intenger+=input[p];
		p++;
	}
	reverse(intenger.begin(),intenger.end());
	for(int i=0;i<intenger.size();i++){
		if(0<i&&i%3==0)
			s+=',';
		s+=intenger[i];
	}
	intenger=s;
	reverse(intenger.begin(),intenger.end());
	p++;
	while(p<input.size()&&fractional.size()<2){
		fractional+=input[p];
		p++;
	}
	while(fractional.size()<2)
		fractional+='0';
	string ans="$"+intenger+"."+fractional;
	if(isMinus)
		ans="("+ans+")";
	cout<<ans<<endl;
	return 0;
}


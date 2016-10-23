#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<string> rot(vector<string> in)
{
	vector<string> out(8,"00000000");
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			out[j][7-i]=in[i][j];
	return out;
}

int main()
{
	vector<string> pat(8);
	for(int i=0;i<8;i++)
		cin>>pat[i];
	for(int i=0;i<3;i++){
		pat=rot(pat);
		cout<<90*(i+1)<<endl;
		for(int j=0;j<8;j++)
			cout<<pat[j]<<endl;
	}
	return 0;
}


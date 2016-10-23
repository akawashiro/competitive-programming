#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	string input;
	while(getline(cin,input))
	{
		for(int i=0;i<input.size();i++)
			if(input[i]==',' || input[i]=='.')
				input[i]=' ';
		stringstream ss(input);
		string s;
		int isFirst=1;
		while(ss>>s)
			if(3<=s.size() && s.size()<=6)
			{
				if(!isFirst)
					cout<<" ";
				isFirst=0;
				cout<<s;
			}
		cout<<endl;
	}
	return 0;
}

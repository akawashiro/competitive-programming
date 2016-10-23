#include <iostream>
#include <string>
using namespace std;

int main()
{
	string source;
	cin >> source;
	int JOI=0;
	int IOI=0;
	for(int i=0;i<source.size()-2;i++){
		if(source[i]=='J'&&source[i+1]=='O'&&source[i+2]=='I')
			JOI++;
		if(source[i]=='I'&&source[i+1]=='O'&&source[i+2]=='I')	
				IOI++;
	}
	cout << JOI << endl << IOI << endl;
	return 0;
}


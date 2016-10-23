#include <iostream>

using namespace std;

int main()
{
	int cup[3];
	cup[0]=1,cup[1]=0,cup[2]=0;

	string s;
	while(cin >> s)
		swap(cup[s[0]-'A'],cup[s[2]-'A']);

	if(cup[0]==1)	cout << "A" << endl;
	if(cup[1]==1)	cout << "B" << endl;
	if(cup[2]==1)	cout << "C" << endl;

	return 0;
}


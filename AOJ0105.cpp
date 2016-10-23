#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main()
{
	map<string,set<int> > index;
	string s;
	while(cin >> s)
	{
		int a;
		cin >> a;
		index[s].insert(a);
	}

	map<string,set<int> >::iterator mitr;
	for(mitr=index.begin();mitr!=index.end();mitr++)
	{
		cout << (*mitr).first << endl;
		set<int>::iterator sitr;
		for(sitr=(*mitr).second.begin();sitr!=(*mitr).second.end();sitr++)
		{
			if(sitr!=(*mitr).second.begin())
				cout << " ";
			cout << (*sitr);
		}
		cout << endl;
	}
	return 0;
}


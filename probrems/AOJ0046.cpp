#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	vector<double> mountain;
	double d;
	while(cin>>d)
		mountain.push_back(d);
	sort(mountain.begin(),mountain.end());
	cout<<mountain.back()-mountain.front()<<endl;
	return 0;
}


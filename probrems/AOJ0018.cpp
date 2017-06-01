#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v;
	int a;
	while(cin >> a)
		v.push_back(a);
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	cout << v[0];
	for(int i=1;i<5;i++)
		cout << " " << v[i];
	cout << endl;
	return 0;
}


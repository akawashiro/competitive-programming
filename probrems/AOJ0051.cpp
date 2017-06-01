#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string mi,ma;
		cin>>mi;
		sort(mi.begin(),mi.end());
		ma=mi;
		reverse(ma.begin(),ma.end());
		stringstream ss1(mi);
		stringstream ss2(ma);
		int a1,a2;
		ss1>>a1;
		ss2>>a2;
		cout<<(a2-a1)<<endl;
	}
	return 0;
}


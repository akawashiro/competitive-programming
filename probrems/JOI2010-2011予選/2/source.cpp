#include <string>
#include <iostream>
using namespace std;

int main()
{
	string purpose;
	int N;
	int ans=0;
	cin >> purpose;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		string s;
		cin >> s;
		s+=s;
		for(int j=0;j<=s.size()-purpose.size();j++)
			if(s.substr(j,purpose.size())==purpose)
			{
				ans++;
				break;
			}
	}
	cout << ans << endl;
	return 0;
}


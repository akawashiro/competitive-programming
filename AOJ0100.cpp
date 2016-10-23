#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long LL;

void solve(int n)
{
	vector<LL> sale(4001,0);
	bool isOutput=false;
	for(int i=0;i<n;i++)
	{
		int a;
		LL b,c;
		cin >> a >> b >> c;
		if(sale[a]<1000000)
		{
			sale[a]+=b*c;
			if(1000000<=sale[a])
			{
				cout << a << endl;
				isOutput=true;
			}
		}
	}
	if(!isOutput)
		cout << "NA" << endl;
}

int main()
{
	int n;
	cin >> n;
	while(n!=0)
	{
		solve(n);
		cin >> n;
	}
	return 0;
}


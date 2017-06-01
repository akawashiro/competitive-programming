#include <iostream>
using namespace std;

int main()
{
		int sum;
		int count=0;
		cin >> sum;
		sum=1000-sum;
		count+=sum/500;
		sum%=500;
		//cout << count << endl;
		count+=sum/100;
		sum%=100;
		//cout << count << endl;
		count+=sum/50;
		sum%=50;
		//cout << count << endl;
		count+=sum/10;
		sum%=10;
		//cout << count << endl;
		count+=sum/5;
		sum%=5;
		count+=sum;

		cout << count << endl;
		return 0;
}


#include <iostream>
using namespace std;

int main()
{
	int N,K;
	cin >> N >> K;
	for(int i=0;i<K;i++)
	{
		int x,y;
		cin >> x >> y;
		x=min(x,N-x+1);
		y=min(y,N-y+1);
		cout << (min(x,y)-1)%3+1 << endl;
	}
	return 0;
}


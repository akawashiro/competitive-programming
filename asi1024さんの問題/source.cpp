#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int M,W,N;
	cin >> N >> W >> M;
	vector<int> shelf(M);
	for(int i=0;i<M;i++)
	{
		cin >> shelf[i];
		if(W<shelf[i])
			return -1;
	}

	int count=0;
	int w=0;
	int n=0;
	for(int i=0;i<M;i++)
	{
		if(n+1<=N && w+shelf[i]<=W)
		{
			n++;
			w+=shelf[i];
		}
		else
		{
			count++;
			n=1;
			w=shelf[i];
		}
	}
	count++;
	cout << count << endl;
}


#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;

int main()
{
	int N;
	vector<int> num;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		int a;
		cin >> a;
		num.push_back(a);
	}

	vector<LL> process(21,0);
	process[num[0]]=1;
	for(int i=1;i<N-1;i++)
	{
		vector<LL> v(21,0);
		for(int j=0;j<21;j++)
		{
			if(0<=j+num[i] && j+num[i]<21)
				v[j+num[i]]+=process[j];
			if(0<=j-num[i] && j-num[i]<21)
				v[j-num[i]]+=process[j];
		}
		process=v;
	}
	cout << process[num[N-1]] << endl;
	return 0;
}


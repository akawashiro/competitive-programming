#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
		vector<int> W,K;
		for(int i=0;i<10;i++){
				int a;
				cin >> a;
				W.push_back(a);
		}
		for(int i=0;i<10;i++){
				int a;
				cin >> a;
				K.push_back(a);
		}
		sort(W.begin(),W.end(),greater<int>());
		sort(K.begin(),K.end(),greater<int>());
		cout << W[0]+W[1]+W[2] << " " << K[0]+K[1]+K[2] << endl;
		return 0;
}


#include <iostream>
using namespace std;

int main()
{
		char table[256];
		for(int i=0;i<256;i++)
				table[i]=i;
		int n;
		cin >> n;
		for(int i=0;i<n;i++){
				char a,b;
				cin >> a >> b;
				table[a]=b;
		}
		int m;
		cin >> m;
		for(int i=0;i<m;i++){
				char a;
				cin >> a;
				cout << table[a];
		}
		cout << endl;
		return 0;
}


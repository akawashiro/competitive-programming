#include <iostream>
using namespace std;

int main()
{
		int A,B;
		A=0;	B=0;
		for(int i=0;i<4;i++){
				int a;
				cin >> a;
				A+=a;
		}
		for(int i=0;i<4;i++){
				int a;
				cin >> a;
				B+=a;
		}
		if(A < B)
				cout << B;
		else 
				cout << A;
		return 0;
}

#include <iostream>
using namespace std;

int main()
{
		int n,A,B;
		A=0;	B=0;
		cin >> n;
		for(int i=0;i<n;i++){
				int a,b;
				cin >> a >> b;
				if(a < b){
						B+=(a+b);
				}else if(b < a){
						A+=(a+b);
				}else{
						A+=a;
						B+=b;
				}
		}
		cout << A << " " << B << endl;
		return 0;
}

#include <iostream>
using namespace std;

int main()
{
		bool students[31];
		for(int i=0;i<31;i++)
				students[i]=false;
		students[0]=true;
		for(int i=0;i<28;i++){
				int a;
				cin >> a;
				students[a]=true;
		}
		for(int i=1;i<31;i++){
				if(!students[i])
						cout << i << endl;
		}
		cout << "\b";
		return 0;
}

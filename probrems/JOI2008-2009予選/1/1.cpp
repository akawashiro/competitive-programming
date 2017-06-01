#include<iostream>
using namespace std;

int main()
{
		for(int i=0;i<3;i++){
				int sh,sm,ss,eh,em,es;
				cin >> sh >> sm >> ss >> eh >> em >> es;
				ss+=3600*sh+60*sm;
				es+=3600*eh+60*em;
				es-=ss;
				//cout << es << endl;
				cout << es/3600 << " ";
				es%=3600;
				cout << es/60 << " ";
				es%=60;
				cout << es << " ";
				cout << endl;
		}
		return 0;
}


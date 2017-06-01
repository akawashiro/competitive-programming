#include <iostream>
#include <string>

using namespace std;

int square[100+10][100+10];

int main()
{
	int n,avoidX,avoidY;
	cin>>n>>avoidX>>avoidY;
	n/=2;
	if(n==1 || (avoidX==n && avoidY==n) 
			|| (avoidX==n+1 && avoidY==n) 
			|| (avoidX==n+1 && avoidY==n+1) 
			|| (avoidX==n && avoidY==n+1))
	   cout<<"NO"<<endl;
	else	
		cout<<"YES"<<endl;
	return 0;
}


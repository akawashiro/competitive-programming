#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int SET=1;
	while(1)
	{
		int n;
		cin>>n;
		if(n==0)
			break;
		vector<string> vs(n);
		for(int i=0;i<n;i++)
			cin>>vs[i];
		cout<<"SET "<<SET<<endl;
		int i;
		for(i=0;i<n;i+=2)
			cout<<vs[i]<<endl;
		for(i=(n%2==0)?n-1:n-2;0<=i;i-=2)
			cout<<vs[i]<<endl;

		SET++;
	}
	return 0;
}


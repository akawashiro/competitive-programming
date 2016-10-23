#include <iostream>

using namespace std;

int main()
{
	for(int time=0;;time++)
	{
		int b,e;
		cin>>b>>e;
		if(b==0 && e==0)
			break;
		if(time!=0)
			cout<<endl;
		int ansNum=0;
		for(int i=b;i<=e;i++)
			if((i%4==0 && i%100!=0) || i%400==0)
			{
				cout<<i<<endl;
				ansNum++;
			}
		if(ansNum==0)
			cout<<"NA"<<endl;
	}
	return 0;
}

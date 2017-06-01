#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

void solve(int total,int n10,int n50,int n100,int n500)
{
	int minNum=(1<<28);
	int b10,b50,b100,b500;
	for(int a10=0;a10<=n10;a10++)
		for(int a50=0;a50<=n50;a50++)
			for(int a100=0;a100<=n100;a100++)
				for(int a500=0;a500<=n500;a500++)
				{
					int pay=a10*10+a50*50+a100*100+a500*500;
					int back=pay-total;
					int num=0;
					if(back<0)
						continue;
					num+=n10-a10+n50-a50+n100-a100+n500-a500;
					num+=back/500;
					back%=500;
					num+=back/100;
					back%=100;
					num+=back/50;
					back%=50;
					num+=back/10;
					if(num<minNum)
					{
						b10=a10;
						b50=a50;
						b100=a100;
						b500=a500;
						minNum=num;
					}
				}

	if(b10!=0)
		cout << "10 " << b10 << endl;
	if(b50!=0)
		cout << "50 " << b50 << endl;
	if(b100!=0)
		cout << "100 " << b100 << endl;
	if(b500!=0)
		cout << "500 " << b500 << endl;
}


int main()
{
	int total,n10,n50,n100,n500;
	cin >> total;
	bool firstline=true;
	while(total!=0)
	{
		if (!firstline) { cout << endl; }
		firstline=false;
		cin >> n10 >> n50 >> n100 >> n500;
		solve(total,n10,n50,n100,n500);
		cin >> total;
	}
	return 0;
}


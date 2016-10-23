#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

char keyMap[10][7]={
	{'#','#','#','#','#','#','#'},
	{'.',',','!','?',' ','#','#'},
	{'a','b','c','#','#','#','#'},
	{'d','e','f','#','#','#','#'},
	{'g','h','i','#','#','#','#'},
	{'j','k','l','#','#','#','#'},
	{'m','n','o','#','#','#','#'},
	{'p','q','r','s','#','#','#'},
	{'t','u','v','#','#','#','#'},
	{'w','x','y','z','#','#','#'}
};

int nowKey,nowNum;
string ans;

void add(char c)
{
	c-='0';
	if(c==0)
	{
		if(nowKey!=0)
			ans+=keyMap[nowKey][nowNum];
		nowKey=0;
		nowNum=0;
	}
	else
	{
		if(nowKey!=c)
		{
			nowKey=c;
			nowNum=0;
		}
		else
		{
			nowNum++;
			if(keyMap[nowKey][nowNum]=='#')
				nowNum=0;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		string input;
		cin >> input;
		
		nowKey=0;
		nowNum=0;
		ans="";
		for(int j=0;j<(int)input.size();j++)
			add(input[j]);
		cout << ans << endl;
	}
	return 0;
}


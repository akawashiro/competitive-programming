#include <iostream>
#include <string>

using namespace std;

int main()
{
	while(1){
		string s,t;
		cin>>s>>t;
		if(s=="0" && t=="0")
			break;
		int hit=0,blow=0;
		for(int i=0;i<4;i++)
			if(s[i]==t[i])
				hit++;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				if(i!=j && s[i]==t[j])
					blow++;
		cout<<hit<<" "<<blow<<endl;
	}
	return 0;
}


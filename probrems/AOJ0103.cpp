//AOJ0103
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(;0<T;T--){
		string s;
		int o,p;
		int b[3];
		o=0,p=0,b[0]=b[1]=b[2]=0;
		while(o<3){
			cin>>s;
			if(s=="HIT"){
				int c=1;
				for(int i=0;i<3;i++)
					if(b[i]==0&&c==1)
						b[i]=1,c=0;
				if(c)
					p++;
			}else if(s=="OUT"){
				o++;
			}else{
				p+=(b[0]+b[1]+b[2]+1);
				b[0]=b[1]=b[2]=0;
			}
		}
		cout<<p<<endl;
	}
	return 0;
}


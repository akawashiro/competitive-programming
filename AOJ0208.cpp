#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	while(1){
		int n;
		string ans;
		scanf("%d",&n);
		if(!n)
			break;
		for(int i=0;0<n;i++){
			int a=n%8;
			if(a==4)
				a++;
			else if(5<=a && a<=7)
				a+=2;
			ans+=a+'0';
			n/=8;
		}
		reverse(ans.begin(),ans.end());
		printf("%s\n",ans.c_str());
	}
	return 0;
}


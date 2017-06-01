#include <string>
#include <math.h>
#include <stdio.h>

using namespace std;

string rec(int n,int k)
{
	if(n==0)
		return "J";
	else if(k<=(int)pow(2,n-1))
		return string((int)pow(2,n-1),'J')+string((int)pow(2,n-1),'O');
	else
		return string((int)pow(2,n-1),'I')+rec(n-1,k-(int)pow(2,n-1));
}

int main()
{
	int k,n;
	scanf("%d%d",&n,&k);
	string ans=rec(n,k);
	printf("%s\n",ans.c_str());
	return 0;
}


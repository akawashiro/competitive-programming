#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

char buf[40];
int inG[40];
int outG[40];

class UNIONFIND
{
	vector<int> data;
	vector<int> scale;
	public:
	UNIONFIND(int n)
	{
		for(int i=0;i<n;i++)
		{
			data.push_back(i);
			scale.push_back(1);
		}
	}
	int root(int n)
	{
		if(data[n]==n)
			return n;
		else
			return data[n]=root(data[n]);
	}
	void set(int x,int y)
	{
		if(root(x)==root(y))
			return;
		scale[root(y)]+=scale[root(x)];
		scale[root(x)]=0;
		data[root(x)]=data[root(y)];
	}
	int size(int n)
	{
		return scale[root(n)];
	}
};


int main()
{
	while(1){
		int n;
		scanf("%d",&n);
		if(n==0)
			break;
		memset(inG,0,sizeof(inG));
		memset(outG,0,sizeof(outG));
		UNIONFIND u(40);
		for(int i=0;i<n;i++){
			int m;
			scanf("%s",buf);
			m=strlen(buf);
			int s=buf[0]-'a',t=buf[m-1]-'a';
			inG[s]++;
			outG[t]++;
			u.set(s,t);
		}
		int nOdd=0,g=-1;
		for(int i=0;i<40;i++)
			if(0<inG[i]){
				if(inG[i]!=outG[i])
					nOdd++;
				if(g!=-1 && u.root(i)!=g)
					nOdd++;
				g=u.root(i);
			}
		if(nOdd)
			printf("NG\n");
		else
			printf("OK\n");
	}
	return 0;
}


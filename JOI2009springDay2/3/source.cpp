#include <vector>
#include <functional>
#include <stdio.h>
#include <algorithm>
#include <utility>

#define PB push_back
#define MP make_pair
#define FI first
#define SE second

using namespace std;
typedef pair<int,int> P;

int isUsed[3000+10];
vector<P> input;
vector<pair<int,P> > cand;

int main()
{
	int n,c,cp=0;
	scanf("%d%d",&n,&c);
	printf("n=%d c=%d\n",n,c);
	{
		int t=0;
		for(int i=0;i<n*2;i++){
			int s,a;
			scanf("%d%d",&s,&a);
			if(a==c){
				t++;
				cp+=s;
				printf("cp=%d\n",cp);
			}
			else
				input.PB(MP(s,a));
		}
		sort(input.begin(),input.end(),greater<P>() );
		vector<pair<int,int> > vp;
		for(int i=0;i<(int)input.size();i++)
			if(t<2 && input[i].SE==0){
				cp+=input[i].FI;
				printf("cp=%d\n",cp);
				t++;
			}else
				vp.PB(input[i]);
		input=vp;
	}
	int m=input.size();
	printf("cp=%d\n",cp);
	printf("input\n");
	for(int i=0;i<m;i++)
		printf("input[%d].FI=%d SE=%d\n",i,input[i].FI,input[i].SE);
	for(int i=0;i<m;i++)
		for(int j=i+1;j<m;j++)
			if(input[i].SE==input[j].SE || input[i].SE==0 || input[j].SE==0)
				cand.PB(MP(input[i].FI+input[j].FI,MP(i,j)));
	/*printf("cand\n");
	for(int i=0;i<(int)cand.size();i++)
		printf("cand[%d].FI=%d SE.FI=%d SE.SE=%d\n",i,cand[i].FI,cand[i].SE.FI,cand[i].SE.SE);*/
	int ans=n;
	sort(cand.begin(),cand.end(),greater<pair<int,P> >() );
	printf("under\n");
	for(int i=0;i<(int)cand.size();i++)
		if(cand[i].FI<=cp && !isUsed[cand[i].SE.FI] && !isUsed[cand[i].SE.SE]){
			printf("cand[%d].FI=%d SE.FI=%d SE.SE=%d\n",i,cand[i].FI,cand[i].SE.FI,cand[i].SE.SE);
			ans--;
			isUsed[cand[i].SE.FI]=1;
			isUsed[cand[i].SE.SE]=1;
		}
	printf("%d\n",ans);
	return 0;
}


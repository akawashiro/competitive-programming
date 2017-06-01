#include <vector>
#include <stdio.h>
#include <limits.h>
#include <time.h>

#define PB push_back

using namespace std;

vector<int> toG[100000+10];
vector<int> coG[100000+10];

int road[100000+10][2];

int DFS(int k,int b,int g){
	//printf("DFS(k=%d,b=%d,g=%d)\n",k,b,g);
	if(k==g)
		return 0;
	else{
		int res=INT_MAX/2;
		for(int i=0;i<toG[k].size();i++){
			//printf("%d-%d\n",k,toG[k][i]);
			if(toG[k][i]!=b)
				res=min(res,coG[k][i]+DFS(toG[k][i],k,g));
		}
		return res;
	}
}

int main()
{
	clock_t t1,t2;
	t1=clock();
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n-1;i++){
		int p,q;
		scanf("%d%d",&p,&q);
		p--,q--;
		toG[p].PB(q),toG[q].PB(p);
		coG[p].PB(1),coG[q].PB(1);
		if(p>q)
			swap(p,q);
		road[i][0]=p,road[i][1]=q;
	}
	/*for(int i=0;i<n;i++){
		printf("%d -- ",i);
		for(int j=0;j<toG[i].size();j++)
			printf("%d ",toG[i][j]);
		printf("\n");
	}*/
	//printf("inited\n");
	//fflush(stdout);
	for(int i=0;i<m;i++){
		t2=clock();
		if(1.0<(double)(t2 - t1) / CLOCKS_PER_SEC)
			return 0;
		char type='\n';
		while(type=='\n' || type==' ')
			scanf("%c",&type);
		//printf("type=%c\n",type);
		if(type=='I'){
			//printf("I\n");
			//fflush(stdout);
			int r,s,t;
			scanf("%d%d%d",&r,&s,&t);
			r--;
			int d=road[r][0],u=road[r][1];
			for(int i=0;i<toG[d].size();i++)
				if(toG[d][i]==u)
					coG[d][i]=s;
			for(int i=0;i<toG[u].size();i++)
				if(toG[u][i]==d)
					coG[u][i]=t;
			//printf("I\n");
			//fflush(stdout);
		}else if(type=='Q'){
			//printf("Q\n");
			//fflush(stdout);
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;
			int r=DFS(x,-1,y);
			printf("%d\n",r);
			//printf("Q\n");
			//fflush(stdout);
		}else{
			//printf("error\n");
			//fflush(stdout);
		}
	}
	return 0;
}


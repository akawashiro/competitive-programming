#include <deque>
#include <limits.h>
#include <stdio.h>

using namespace std;

int land[250][250];
int rowMax[250][250];
int rowMin[250][250];
int ansMax[250][250];
int ansMin[250][250];

int main()
{
	int N,B,K;
	scanf("%d%d%d",&N,&B,&K);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			scanf("%d",&land[i][j]);
		deque<int> deqMax,deqMin;
		for(int j=0;j<B;j++)
		{
			while(!deqMax.empty() && land[i][deqMax.back()]<=land[i][j])
				deqMax.pop_back();
			deqMax.push_back(j);
			while(!deqMin.empty() && land[i][deqMin.back()]>=land[i][j])
				deqMin.pop_back();
			deqMin.push_back(j);
		}
		rowMax[i][0]=land[i][deqMax.front()];
		rowMin[i][0]=land[i][deqMin.front()];
		//printf("rowMax[%d][%d]=%d\n",i,0,rowMax[i][0]);
		//printf("rowMin[%d][%d]=%d\n",i,0,rowMin[i][0]);
		for(int j=B;j<N;j++)
		{
			if(deqMax.front()==j-B)
				deqMax.pop_front();
			if(deqMin.front()==j-B)
				deqMin.pop_front();
			while(!deqMax.empty() && land[i][deqMax.back()]<=land[i][j])
				deqMax.pop_back();
			deqMax.push_back(j);
			while(!deqMin.empty() && land[i][deqMin.back()]>=land[i][j])
				deqMin.pop_back();
			deqMin.push_back(j);

			rowMax[i][j-B+1]=land[i][deqMax.front()];
			rowMin[i][j-B+1]=land[i][deqMin.front()];

			//printf("rowMax[%d][%d]=%d\n",i,j-B,rowMax[i][j-B]);
			//printf("rowMin[%d][%d]=%d\n",i,j-B,rowMin[i][j-B]);
		}
	}
	for(int y=0;y+B<=N;y++)
		for(int x=0;x+B<=N;x++)
		{
			ansMax[y][x]=INT_MIN;
			ansMin[y][x]=INT_MAX;
			for(int i=y;i<y+B;i++)
			{
				ansMax[y][x]=max(ansMax[y][x],rowMax[i][x]);
				ansMin[y][x]=min(ansMin[y][x],rowMin[i][x]);
			}
			//printf("y=%d x=%d max=%d min=%d\n",y,x,ansMax[y][x],ansMin[y][x]);
		}
	for(int i=0;i<K;i++)
	{
		int y,x;
		scanf("%d%d",&y,&x);
		y--,x--;
		printf("%d\n",ansMax[y][x]-ansMin[y][x]);
	}
	return 0;
}



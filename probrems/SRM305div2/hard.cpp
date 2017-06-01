#include <algorithm>
#include <queue>

using namespace std;

class QUE
{
	public:
		int m,c,b,d;
};

class Cannibals
{
	public:
		
		int dist[100+10][100+10][2];

		int minCrossings(int M, int C, int R)
		{
			fill(&dist[0][0][0],&dist[100+9][100+9][1],(1<<28));

			QUE q;
			queue<QUE> que;

			q.m=M,q.c=C,q.b=0,q.d=0;
			que.push(q);

			while(!que.empty())
			{
				int m=que.front().m;
				int c=que.front().c;
				int b=que.front().b;
				int d=que.front().d;
				que.pop();
				
				//printf("m=%d c=%d b=%d d=%d \n",m,c,b,d);

				int om=M-m;
				int oc=C-c;
				int ob=(b+1)%2;

				if((c<=m || m==0) && (oc<=om || om==0) && d<dist[m][c][b])
				{
					dist[m][c][b]=d;

					int bm,bc;
					for(bm=0;bm<=m;bm++)
						for(bc=0;bc<=c;bc++)
							if((c-bc<=m-bm || m-bm==0) && (bc<=bm || bm==0) && 0<bm+bc && bm+bc<=R)
							{
								q.m=om+bm,q.c=oc+bc,q.b=ob,q.d=d+1;
								que.push(q);
							}
				}
			}

			return dist[M][C][1]==(1<<28) ? -1 : dist[M][C][1];
		}
};


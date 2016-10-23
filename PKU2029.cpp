#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int P[110][110];
int F[110][110];

int main()
{
	while(1)
	{
		int N,H,W,h,w;
		cin>>N;
		if(N==0)
			break;
		cin>>W>>H;
		memset(P,0,sizeof(P));
		for(int i=0;i<N;i++)
		{
			int a,b;
			cin>>a>>b;
			a--,b--;
			P[b][a]=1;
		}
		cin>>w>>h;

		/*for(int y=0;y<H;y++)
		{
			for(int x=0;x<W;x++)
			{
				cout<<P[y][x];
			}
			cout<<endl;
		}
		cout<<endl;*/
		
		int ans=0;
		memset(F,0,sizeof(F));
		for(int y=0;y+h<=H;y++)
			for(int x=0;x+w<=W;x++)
			{
				//cout<<x<<","<<y<<endl;
				if(y==0 && x==0)
				{
					for(int i=0;i<h;i++)
						for(int j=0;j<w;j++)
						{
							//cout<<i<<","<<j<<endl;
							F[y][x]+=P[i][j];
						}
					//cout<<"F"<<endl;
				}
				else if(y==0)
				{
					F[y][x]=F[y][x-1];
					for(int i=0;i<h;i++)
					{
						F[y][x]-=P[i][x-1];
						F[y][x]+=P[i][x+w-1];
					}
				}
				else
				{
					F[y][x]=F[y-1][x];
					for(int i=x;i<x+w;i++)
					{
						F[y][x]-=P[y-1][i];
						F[y][x]+=P[y+h-1][i];
					}
				}
				ans=max(ans,F[y][x]);
			}
		cout<<ans<<endl;
	}
}

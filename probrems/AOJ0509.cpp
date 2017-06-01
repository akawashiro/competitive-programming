#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

class END
{
	public:
		int pos;
		bool isStart;

		bool operator<(const END &e)
		const{
			if(pos==e.pos)
				return isStart;
			return (pos<e.pos);
		}
};

int n,type;

void solve()
{
	vector<vector<END> > sheet(10000);
	int maxY=0,maxX=0;

	for(int i=0;i<n;i++)
	{
		int l,b,r,c;
		scanf("%d%d%d%d",&l,&b,&r,&c);
		maxY=max(maxY,c);
		maxX=max(maxX,r);
		for(int y=b;y<c;y++)
		{
			END e;
			e.pos=l,e.isStart=true;
			sheet[y].push_back(e);
			e.pos=r,e.isStart=false;
			sheet[y].push_back(e);
		}
	}

	int ans=0;
		for(int y=0;y<maxY;y++)
		{
			sort(sheet[y].begin(),sheet[y].end());

			int s=0;
			int p=0;
			for(int x=0;x<(int)sheet[y].size();x++)
			{
				if(0<s)
					ans+=sheet[y][x].pos-p;
				p=sheet[y][x].pos;

				if(sheet[y][x].isStart)
					s++;
				else
					s--;
			}
		}
		printf("%d\n",ans);
		ans=0;

	if(type==2)
	{
		vector<bool> pre(maxX,false);
		for(int y=0;y<=maxY;y++)
		{
			//printf("y=%d\n",y);
			vector<bool> now(maxX,false);
			if(y!=maxY)
			{
				int s=0;
				int p=0;
				sort(sheet[y].begin(),sheet[y].end());
				for(int x=0;x<(int)sheet[y].size();x++)
				{
					if(0<s)
						for(int i=p;i<sheet[y][x].pos;i++)
							now[i]=true;
					p=sheet[y][x].pos;

					if(sheet[y][x].isStart)
						s++;
					else
						s--;
				}
			}

			if(now[0])
				ans++;
			if(now[maxX-1])
				ans++;
			for(int x=0;x<maxX;x++)
			{
				if(pre[x]^now[x])
					ans++;
				if(x+1<maxX && now[x]^now[x+1])
					ans++;
			}

			pre=now;
		}
	printf("%d\n",ans);
	}

}

int main()
{
	while(1)
	{
		scanf("%d%d",&n,&type);
		if(n==0 && type==0)
			break;
		solve();
	}
	return 0;
}


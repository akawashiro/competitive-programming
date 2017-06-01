#include <sstream>
#include <string>
#include <vector>

typedef long long LL;
using namespace std;

class REC
{
	public:
		LL left,down,right,up;
};

bool contain(REC r,LL x,LL y)
{
	return (r.left<x && x<r.right && r.down<y && y<r.up);
}

LL calc(REC r,LL x,LL y)
{
	return (r.left-r.right)*(y-r.down)+(r.down-r.up)*(r.left-x);
}

bool intersect(REC r,REC s)
{
	if(s.left==s.right && (s.left==r.left || s.left==r.right) )
		return !(s.up<r.down || r.up<s.down); 
	else if(s.down==s.up && (s.up==r.down || s.down==r.up) )
		return !(s.right<r.left || r.right<s.left);
	else
		return calc(r,s.left,s.down)*calc(r,s.right,s.up)<=0 && calc(s,r.left,r.down)*calc(s,r.right,r.up)<=0;	
}

class RectangleCrossings
{
	public:
		vector <int> countAreas(vector <string> rectangles, vector <string> segments)
		{
			int rN=rectangles.size();
			int sN=segments.size();
			vector<REC> rec(rN);
			vector<REC> seg(sN);
			for(int i=0;i<rN;i++)
			{
				stringstream ss(rectangles[i]);
				ss >> rec[i].left >> rec[i].down >> rec[i].right >> rec[i].up;
			}
			for(int i=0;i<sN;i++)
			{
				stringstream ss(segments[i]);
				ss >> seg[i].left >> seg[i].down >> seg[i].right >> seg[i].up;
			}

			vector<int> ans(2,0);
			for(int i=0;i<rN;i++)
			{
				bool e=false;
				bool s=false;
				for(int j=0;j<sN;j++)
				{
					if(contain(rec[i],seg[j].left,seg[j].down) || 
							contain(rec[i],seg[j].right,seg[j].up))
						e=true;
					REC r;
					r.left=rec[i].left,r.down=rec[i].down;
					r.right=rec[i].right,r.up=rec[i].down;
					if(intersect(r,seg[j]))
					{
						//printf("down\n");
						s=true;
					}
					r.left=rec[i].left,r.down=rec[i].up;
					r.right=rec[i].right,r.up=rec[i].up;
					if(intersect(r,seg[j]))
					{
						//printf("up\n");
						s=true;
					}
					r.left=rec[i].left,r.down=rec[i].down;
					r.right=rec[i].left,r.up=rec[i].up;
					if(intersect(r,seg[j]))
					{
						//printf("left\n");
						s=true;
					}
					r.left=rec[i].right,r.down=rec[i].down;
					r.right=rec[i].right,r.up=rec[i].up;
					if(intersect(r,seg[j]))
					{
						//printf("right\n");
						s=true;
					}
				}
				int S=(rec[i].up-rec[i].down)*(rec[i].right-rec[i].left);
				if(e)
					ans[0]+=S;
				else if(s)
					ans[1]+=S;
			}

			return ans;
		}
};


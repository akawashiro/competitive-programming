#include <vector>
#include <string>
using namespace std;

class RevealTriangle
{
	public:
		vector<string> tri;
		void solve(int d,int w)
		{
			if(tri[d][w-1]!='?' && tri[d][w]!='?')
				return;

			if(tri[d][w-1]=='?' && tri[d][w]=='?')
				solve(d,w+1);
			if(tri[d][w-1]=='?')
			{
				int a=(tri[d+1][w-1]-'0')-(tri[d][w]-'0')+10;
				tri[d][w-1]=a%10+'0';
			}
			if(tri[d][w]=='?')
			{
				int a=(tri[d+1][w-1]-'0')-(tri[d][w-1]-'0')+10;
				tri[d][w]=a%10+'0';
			}
			return;
		}

		vector <string> calcTriangle(vector <string> _tri)
		{
			tri=_tri;
			for(int d=tri.size()-2;0<=d;d--)
				for(int w=1;w<tri[d].size();w++)
					solve(d,w);
			return tri;
		}
};


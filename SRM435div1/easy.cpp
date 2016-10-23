#include <vector>
using namespace std;

class CellRemoval
{
	public:
		int cellsLeft(vector <int> parent, int deletedCell)
		{
			int ans=0;
			parent[deletedCell]=-2;
			for(int i=0;i<parent.size();i++)
			{
				bool isLeaf=true;
				for(int j=0;j<parent.size();j++)
					if(parent[j]==i)
					{
						isLeaf=false;
						break;
					}
				if(!isLeaf)
					continue;
				int p=i;
				while(p!=-1 && p!=-2)
					p=parent[p];
				if(p==-1)
					ans++;
			}
			return ans;
		}
};


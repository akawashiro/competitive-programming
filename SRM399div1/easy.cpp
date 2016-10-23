#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;

class AvoidingProduct
{
	public:
		bool M[1000000];
		vector<int> result;
		int n,resultD;

		void check(int a,int b,int c)
		{
			LL t=(LL)a*(LL)b*(LL)c;
			LL d=abs(t-n);
			if(d<resultD)
			{
				resultD=(int)d;
				result.clear;
				result.push_back(a);
				result.push_back(b);
				result.push_back(c);
			}
		}

		vector<int> getTriple(vector<int> vi,int _n)
		{
			n=_n;
			memset(M,false,sizeof(M));
			for(int i=0;i<vi.size();i++)
				M[vi[i]]=true;
			resultD=10000000000;
			int m=3000;
			for(int a=1;a<=m;a++)
				if(!M[a])
					for(int b=1;b<=m;b++)
						if(!M[b])
						{
							int key=n/(a*b);
							if(key==0)
								key++;
							for(int c=key;0<c;c--)
								if(!M[c])
								{
									check(a,b,c);
									break;
								}
							for(int c=key,D=2;0<D;D--)
								if(!M[c])
								{
									check(a,b,c);
									D--;
								}
						}
			return result;
		}
};


#include <algorithm>
#include <vector>

using namespace std;

class LIQUID
{
	public:
		int p,a;
		bool operator<(const LIQUID &l)
			const{
				return p<l.p;
			}
};

class MixingLiquids
{
	public:
		double howMuch(vector <int> percent, vector <int> amount, int need)
		{
			vector<LIQUID> dense;
			vector<LIQUID> thin;
			double add=0.0;
			for(int i=0;i<(int)percent.size();i++)
			{
				LIQUID l;
				l.p=percent[i],l.a=amount[i];
				if(need<percent[i])
					dense.push_back(l);
				else if(percent[i]<need)
					thin.push_back(l);
				else
					add+=amount[i];
			}

			int totalSub,a,b;
			for(int i=0;i<(int)dense.size();i++)
				a+=(dense[i].p-need)*dense[i].a;
			for(int i=0;i<(int)thin.size();i++)
				b+=(need-thin[i].p)*thin[i].a;
			totalSub=min(a,b);

			double dAmount=0,tAmount=0;
			a=totalSub,b=totalSub;
			sort(dense.begin(),dense.end());
			for(int i=0;0<a && i<(int)dense.size();i++)
			{
				if(0<=a-(dense[i].p-need)*dense[i].a)
				{
					dAmount+=dense[i].a;
					a-=(dense[i].p-need)*dense[i].a;
				}
				else
				{
					dAmount+=(double)a/(double)(dense[i].p-need);
					a=0;
				}
			}
			sort(thin.begin(),thin.end());
			reverse(thin.begin(),thin.end());
			for(int i=0;0<b && i<(int)thin.size();i++)
			{
				if(0<=b-(need-thin[i].p)*thin[i].a)
				{
					tAmount+=thin[i].a;
					b-=(need-thin[i].p)*thin[i].a;
				}
				else
				{
					tAmount+=(double)b/(double)(need-thin[i].p);
					b=0;
				}
			}

			return dAmount+tAmount+add;
		}
};


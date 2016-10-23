#include <string>
#include <sstream>
#include <vector>

using namespace std;

class CrazyComponents
{
	public:

		double cache[55][(1<<15)];
		vector<int> require[15];
		vector<double> income;
		vector<double> expense;
		int k;
		int n;

		double rec(int time,int state)
		{
			double &r=cache[time][state];
			if(r!=-1.0)
				;
			else if(time==k)
				r=0.0;
			else
			{
				r=0.0;
				for(int i=0;i<n;i++)
				{
					double d=0.0;
					bool b=true;
					for(int j=0;j<require[i].size();j++)
						if( !((1<<require[i][j]) & state) )
							b=false;
					d=rec(time+1,state)/(double)n;
					if(b)
						d=max(d,(rec(time+1,(state | (1<<i)))+income[i]-expense[i])/(double)n );
					r+=d;
				}
			}

			return r;
		}

		double expectedProfit(int _k,vector<string> components, vector <int> _income, vector <int> _expense)
		{
			k=_k;
			n=_income.size();
			for(int i=0;i<n;i++)
			{
				income.push_back((double)_income[i]);
				expense.push_back((double)_expense[i]);
			}

			for(int i=0;i<n;i++)
			{
				stringstream ss(components[i]);
				int a;
				while(ss >> a)
					require[i].push_back(a);
			}

			for(int i=0;i<=k;i++)
				for(int j=0;j<(1<<n);j++)
					cache[i][j]=-1.0;

			return rec(0,0);
		}
};


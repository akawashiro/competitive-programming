#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

class ImportsList
{
	public:

		vector<string> requires;
		int n;

		vector<int> tpl;
		vector<bool> isAdded;

		void tpl_main()
		{
			isAdded=vector<bool>(n,false);
			for(int i=0;i<n;i++)
				if(!isAdded[i])
					tpl_rec(i);
			reverse(tpl.begin(),tpl.end());
		}

		void tpl_rec(int index)
		{
			for(int i=0;i<n;i++)
				if(requires[index][i]=='Y' && !isAdded[i])
					tpl_rec(i);
			isAdded[index]=true;
			tpl.push_back(index);
		}

		vector<vector<int> > req;
		vector<vector<bool> > req_cache;
		vector<bool> isGened;

		void req_main()
		{
			isGened=vector<bool>(n,false);
			req_cache=vector<vector<bool> >(n);
			
			req=vector<vector<int> >(n);
			
			for(int i=0;i<n;i++)
			{
				vector<bool> v=req_rec(i);
				for(int j=0;j<n;j++)
					if(v[j])
						req[i].push_back(j);
			}
		}

		vector<bool> req_rec(int index)
		{
			if(isGened[index])
				return req_cache[index];
				
			vector<bool> v(n,false);
			for(int i=0;i<n;i++)
			{
				if(requires[index][i]=='Y')
				{
					vector<bool> x=req_rec(i);
					for(int j=0;j<n;j++)
						if(x[j])
							v[j]=true;
				}
			}
			v[index]=true;
			
			isGened[index]=true;
			return req_cache[index]=v;
		}

		vector<int> importsCount(vector<string> _requires)
		{
			requires=_requires;
			n=requires.size();

			tpl_main();
			req_main();
			
			/*for(int i=0;i<n;i++)
				printf("tpl[%d]=%d\n",i,tpl[i]);
			printf("\n");
			for(int i=0;i<n;i++)
			{
				printf("req[%d]=",i);
				for(int j=0;j<req[i].size();j++)
					printf("%3d",req[i][j]);
				printf("\n");
			}
			printf("\n");*/

			vector<int> ans(n,0);
			for(int index=0;index<n;index++)
			{
				vector<bool> v(n,false);
				for(int i=0;i<n;i++)
					if(requires[index][i]=='Y')
						v[i]=true;
				v[index]=false;

				//printf("ans[%d] =",index);
				for(int i=0;i<n && count(v.begin(),v.end(),true)!=0;i++)
				{
					if(v[tpl[i]])
					{
						//printf("%3d",tpl[i]);
						for(int j=0;j<req[tpl[i]].size();j++)
							v[req[tpl[i]][j]]=false;
						ans[index]++;
					}
				}
				//printf("\n");
			}

			return ans;
		}
};


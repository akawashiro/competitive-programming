#include <string>
#include <vector>
using namespace std;

class DNAString
{
	public:
		int minChanges(int maxPeriod, vector <string> _dna)
		{
			int tr[256];
			tr['A']=0,tr['C']=1,tr['G']=2,tr['T']=3;

			string dna;
			for(int i=0;i<_dna.size();i++)
				dna+=_dna[i];
			int n=dna.size();
			int ans=(1<<30);

			for(int period=1;period<=maxPeriod;period++)
			{
				vector<vector<int> > freq(period,vector<int>(4,0));
				for(int i=0;i<n;i++)
					freq[i%period][tr[dna[i]]]++;

				int r=0;
				for(int i=0;i<period;i++)
				{
					int m=0,s=0;
					for(int j=0;j<4;j++)
					{
						m=max(m,freq[i][j]);
						s+=freq[i][j];
					}
					r+=s-m;
				}
				ans=min(ans,r);
			}

			return ans;
		}
};


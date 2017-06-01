#include <string>
#include <sstream>
#include <vector>

using namespace std;

class GuitarChords
{
	public:

		vector<int> strings;
		vector<int> chord;
		vector<int> play;
		int sN,cN,ans,all;

		int s2i(string s)
		{
			if(s=="A")	return 0;
			if(s=="A#")	return 1;
			if(s=="B")	return 2;
			if(s=="C")	return 3;
			if(s=="C#")	return 4;
			if(s=="D")	return 5;
			if(s=="D#")	return 6;
			if(s=="E")	return 7;
			if(s=="F")	return 8;
			if(s=="F#")	return 9;
			if(s=="G")	return 10;
			if(s=="G#")	return 11;
			else		return -1;
		}

		int difficulty()
		{
			int mask=0;
			for(int i=0;i<sN;i++)
				mask=(mask | (1<<play[i]));
			if(mask!=all)
				return (1<<28);

			vector<int> fred;
			for(int i=0;i<sN;i++)
			{
				int a=play[i]-strings[i];
				if(a!=0)
					fred.push_back(a%12);
			}
			
			if(fred.size()==0)
				return 0;
			int r=(1<<28);
			int fN=fred.size();
			for(mask=0;mask<(1<<fN);mask++)
			{
				int t=0;
				for(int i=0;i<fN;i++)
					for(int j=i+1;j<fN;j++)
					{
						int a=(mask & (1<<i)) ? fred[i]+12 : fred[i];
						int b=(mask & (1<<j)) ? fred[j]+12 : fred[j];
						if(a<b)
							swap(a,b);
						t=max(t,a-b);
					}
				t++;
				r=min(t,r);
			}
			return r;
		}

		void DFS(int index)
		{
			if(index==sN)
			{
				ans=min(ans,difficulty());
				return;
			}
			for(int i=0;i<cN;i++)
			{
				play[index]=chord[i];
				DFS(index+1);
			}
			return;
		}

		int stretch(vector<string> _strings,vector<string> _chord)
		{
			sN=_strings.size();
			cN=_chord.size();
			strings=vector<int>(sN);
			chord=vector<int>(cN);
			play=vector<int>(sN);

			for(int i=0;i<sN;i++)
				strings[i]=s2i(_strings[i]);
			all=0;
			for(int i=0;i<cN;i++)
			{
				chord[i]=s2i(_chord[i]);
				all=(all | (1<<chord[i]));
			}

			ans=(1<<28);
			DFS(0);

			return ans;
		}
};


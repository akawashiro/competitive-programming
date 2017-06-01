#include <string>
#include <iostream>
using namespace std;

class TwoStringMasks
{
	public:
		string shortestCommon(string s1, string s2)
		{
			string s1_1,s1_2,s2_1,s2_2;
			char c=s1[0];
			int index=0;
			while(c!='*')
			{
				s1_1+=c;
				index++;
				c=s1[index];
			}
			index++;
			while(index!=(int)s1.size())
			{
				c=s1[index];
				s1_2+=c;
				index++;
			}

			c=s2[0];
			index=0;
			while(c!='*')
			{
				s2_1+=c;
				index++;
				c=s2[index];
			}
			index++;
			while(index!=(int)s2.size())
			{
				c=s2[index];
				s2_2+=c;
				index++;
			}

			//cout << s1_1 << "---";
			//cout << s1_2 << endl;
			//cout << s2_1 << "---";
			//cout << s2_2 << endl;
			//cout << endl;

			int dif=(int)s1.size()-(int)s2.size();
			int ast=0;
			if(ast+dif<0)
				ast=dif*(-1);

			for(ast;ast<100;ast++)
			{
				string t,u,v;
				t=s1_1+string(ast,'*')+s1_2;
				u=s2_1+string(ast+dif,'*')+s2_2;

				//cout << t << endl;
				//cout << u << endl;

				for(int i=0;i<(int)t.size();i++)
				{
					if(t[i]==u[i])
						v+=t[i];
					else if(t[i]=='*')
						v+=u[i];
					else if(u[i]=='*')
						v+=t[i];
					else if(t[i]!=u[i])
						break;
				}

				//cout << v << endl;
				//cout << endl;

				if(v.size()==t.size())
					return v;
			}

			return "impossible";
		}
};


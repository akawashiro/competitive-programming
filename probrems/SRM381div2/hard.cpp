#include <algorithm>
#include <cstdio>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class TheNumbersLord
{
	public:
		string create(vector <int> input, int n)
		{
			int m=input.size(),greatest=0;
			string gs;
			vector<string> numbers(m);
			for(int i=0;i<m;i++)
			{
				char s[100];
				sprintf(s,"%d",input[i]);
				numbers[i]=s;
				if(greatest<input[i])
					gs=numbers[i],greatest=input[i];
			}
			
			printf("gs=%s",gs.c_str());
			
			while(numbers.size()!=n)
				numbers.push_back(gs);

			//ここから説明します
				
			for(int i=0;i<n;i++)
				for(int j=0;j<n-1;j++)
					if(numbers[j]+numbers[j+1]<numbers[j+1]+numbers[j])
						swap(numbers[j],numbers[j+1]);

			string ans;
			for(int i=0;i<n;i++)
				ans+=numbers[i];

			return ans;
		}
};


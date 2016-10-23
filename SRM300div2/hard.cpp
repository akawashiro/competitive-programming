#include <string>

using namespace std;

class CircleOrder
{
	public:
		string firstOrder(string circle)
		{
			circle+=circle;
			int n=circle.size();
			string ans;
			
			int a=0;
			for(int i=0;i<n;i++)
				if('a'<=circle[i] && circle[i]<='z')
					a++;
			a/=2;

			while(1)
			{
				string canMove;
				char m='z'+1;
				for(int i=0;i<n;i++)
				{
					if('a'<=circle[i] && circle[i]<='z')
					{
						char dist=circle[i]-'a'+'A';
						for(int j=i-1;0<=j;j--)
						{
							if('a'<=circle[j] && circle[j]<='z')
								break;
							if(circle[j]==dist && circle[i]<m)
								m=circle[i];
						}
						for(int j=i+1;j<n;j++)
						{
							if('a'<=circle[j] && circle[j]<='z')
								break;
							if(circle[j]==dist && circle[i]<m)
								m=circle[i];
						}
					}
				}
				if(m=='z'+1)
					break;
				ans.push_back(m);
				for(int i=0;i<n;i++)
				{
					if(circle[i]==m)
						circle[i]='#';
					if(circle[i]==m-'a'+'A')
						circle[i]-=('A'-'a');
				}
			}
			
			return ((int)ans.size()==a) ? ans : "NONE";
		}
};


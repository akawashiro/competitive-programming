#include <stack>
#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <vector>

using namespace std;

double string2double(string s)
{
	stringstream ss(s);
	double a;
	ss>>a;
	return a;
}

int main()
{
	char input[100];
	while(cin.getline(input,sizeof(input)))
	{
		stringstream ss(input);
		vector<string> vs;
		string s;
		while(ss>>s)
			vs.push_back(s);
		/*for(int i=0;i<vs.size();i++)
			cout<<vs[i]<<" ";
		cout<<"e"<<endl;*/
		stack<double> st;
		for(int i=0;i<vs.size();i++)
		{
			if(vs[i]!="-" && vs[i]!="+" && vs[i]!="*" && vs[i]!="/")
			{
				st.push(string2double(vs[i]));
			}
			else
			{
				double b=st.top();
				st.pop();
				double a=st.top();
				st.pop();
				if(vs[i]=="+")
					st.push(a+b);
				else if(vs[i]=="*")
					st.push(a*b);
				else if(vs[i]=="-")
					st.push(a-b);
				else
				{
					if(b!=0.0)
						st.push(a/b);
					else
						st.push(0);
				}
			}
		}
		//cout<<st.top()<<endl;
		printf("%lf\n",st.top());
	}
	return 0;
}


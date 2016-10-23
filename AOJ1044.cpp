#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	while(1)
	{
		string input,type;
		cin>>input>>type;
		if(type=="X")
			break;

		vector<string> element;
		string buf;
		for(int pos=0;pos<input.size();pos++)
		{
			char c=input[pos];
			if('A'<=c && c<='Z')
			{
				if(buf!="")
					element.push_back(buf);
				buf="";
				buf+=(c-'A'+'a');
			}
			else if(c=='_')
			{
				element.push_back(buf);
				buf="";
			}
			else
			{
				buf+=c;
			}
		}
		element.push_back(buf);
		/*for(int i=0;i<element.size();i++)
			cout<<element[i]<<" ";
		cout<<endl;*/
		if(type=="L")
		{
			cout<<element[0];
			for(int i=1;i<element.size();i++)
			{
				cout<<(char)(element[i][0]-'a'+'A');
				for(int j=1;j<element[i].size();j++)
					cout<<element[i][j];
			}
			cout<<endl;
		}
		else if(type=="U")
		{
			for(int i=0;i<element.size();i++)
			{
				cout<<(char)(element[i][0]-'a'+'A');
				for(int j=1;j<element[i].size();j++)
					cout<<element[i][j];
			}
			cout<<endl;

		}
		else
		{
			for(int i=0;i<element.size();i++)
			{
				if(i!=0)
					cout<<"_";
				cout<<element[i];
			}
			cout<<endl;
		}
	}
	return 0;
}


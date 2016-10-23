#include <list>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class ORG
{
	public:
		ORG *parent;
		string name;
		list<ORG> cld;
		int prt(string pre)
		{
			cout << pre << name << endl;
			for(list<ORG>::iterator itr=cld.begin();itr!=cld.end();itr++)
				(*itr).prt(pre+"+");
			return 0;
		}
		int hire(string emp,string worker)
		{
			if(emp==name)
			{
				ORG o;
				o.name=worker,o.parent=this;
				cld.push_back(o);
			}
			else
			{
				for(list<ORG>::iterator itr=cld.begin();itr!=cld.end();itr++)
					(*itr).hire(emp,worker);
			}
			return 0;
		}
		int fire(string target)
		{
			for(list<ORG>::iterator itr=cld.begin();itr!=cld.end();itr++)
				if((*itr).name==target)
				{
					//cout << "discover\n";
					if((*itr).cld.size()==0)
					{
						//cout << target << endl;
						cld.erase(itr);
						break;
					}
					else
					{
						(*itr).name=(*itr).cld.begin()->name;
						(*itr).fire((*itr).name);
					}
					return 0;
				}
				else
				{
					(*itr).fire(target);
				}
			return 0;
		}
};

int main()
{
	ORG root;
	root.name="###";
	root.parent=NULL;
	string apRoot;
	cin >> apRoot;
	root.hire("###",apRoot);
	while(1)
	{
		string s1,s2,s3;
		if(!(cin >> s1))
		{
			cout << s1 << endl;
			return 0;
		}
		else if(s1=="print")
		{
			root.cld.begin()->prt("");
			printf("------------------------------------------------------------\n");
		}
		else if(s1=="fire")
		{
			//cout << "fire\n";
			cin >> s2;
			root.fire(s2);
		}
		else
		{
			cin >> s2 >> s3;
			root.hire(s1,s3);
		}
		//cout << s1 << " " << s2 << " " << s3 << endl;
		//root.cld.begin()->prt("");
		//printf("------------------------------------------------------------\n");
	}
}


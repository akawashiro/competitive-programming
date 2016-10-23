#include <vector>
#include <string>
#include <map>
#include <list>
using namespace std;

class BatchSystem{
		public:
				vector <int> schedule(vector <int> duration, 
								vector <string> user);
};

/*int nametonum(string name,vector<string> table)
{
		for(int i=0;i<table.size();i++)
				if(table[i]==name)
						return i;
		return -1;
}*/

vector<int> BatchSystem::schedule(vector <int> duration, 
				vector <string> user)
{
		vector<string> table;
		for(int i=0;i<(int)user.size();i++){
				bool isresisted=false;
				for(int j=0;j<(int)table.size();j++)
						if(table[j]==user[i]){
								isresisted=true;
								break;
						}
				if(!isresisted)
						table.push_back(user[i]);
		}
		multimap<int,list<int> > tasklist;
		for(int i=0;i<(int)table.size();i++){
				int total=0;
				list<int> task;
				for(int j=0;j<(int)duration.size();j++){
						if(table[i]==user[j]){
								total+=duration[j];
								task.push_back(j);
						}
				}
				tasklist.insert(make_pair(total,task));
		}
		vector<int> ans(duration.size());
		int ntask=0;
		for(multimap<int,list<int> >::iterator it=tasklist.begin();
						it!=tasklist.end();it++){
				for(list<int>::iterator jt=(*it).second.begin();
								jt!=(*it).second.end();jt++){
						ans[(*jt)]=ntask;
						ntask++;
				}
		}
		return ans;
}


#include <list>
#include <stdio.h>
using namespace std;

class LockersDivTwo{
		public:
				int lastOpened(int N);
};

int LockersDivTwo::lastOpened(int N)
{
		if(N==1)
				return 1;
		list<int> locker;
		for(int i=1;i<=N;i++)
				locker.push_back(i);
		for(int i=1;1<locker.size();i++){
				for(list<int>::iterator it=locker.begin();it!=locker.end();){
						it=locker.erase(it);
						for(int j=0;j<i && it!=locker.end();j++)
								it++;
				}
		}
		return locker.front();
}

int main()
{
		LockersDivTwo l;
		printf("%d\n",l.lastOpened(17));
}

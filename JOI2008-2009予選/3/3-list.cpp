#include <iostream>
#include <iterator>
#include <list>
using namespace std;

int play(list<int> l,int p)
{
		list<int>::iterator it=l.begin();
		for(int i=0;i<p;i++)
				it++;

		/*list<int>::iterator tit;
		for(tit=l.begin();tit!=l.end();tit++)
				cout << *tit << " ";
		cout << endl;*/

		list<int>::iterator sit,eit,end;
		sit=it;	eit=it;	
		//end=l.end();	end--;
		while(*sit==*it){
				if(sit==l.begin())
						goto B1;
				sit--;
		}
		sit++;
B1:
		while(*it==*eit){
				if(eit==l.end())
						break;
				eit++;
		}

		if(4 <= distance(sit,eit)){

				//cout << "erase" << endl;

				list<int>::iterator pit;
				if(sit==l.begin() && eit==end){
						return 0;
				}/*else if(sit==l.begin() && eit!=end){
						l.erase(sit,eit);
						return play(l,l.begin());
				}*/else{
						//pit=sit;	sit--;
						//l.erase(sit,eit);
						pit=l.erase(sit,eit);
						return play(l,distance(l.begin(),pit)-1);
				}
		}else{

				//cout << "return" << endl;
				
				return l.size();
		}
}

int main()
{
		list<int> chara;
		int N;
		cin >> N;
		for(int i=0;i<N;i++){
				int a;
				cin >> a;
				chara.push_back(a);
		}

		//cout << "a" << endl;
		
		int min=N;
		list<int>::iterator it;
		for(it=chara.begin();it!=chara.end();it++){
				int old=*it;
				for(int i=1;i<=3;i++){
						if(i!=old){
								*it=i;
								int a=play(chara,distance(chara.begin(),it)-1);
								min = (a<min) ? a : min;
						}
				}
				*it=old;
		}
		cout << min << endl;
		return 0;
}


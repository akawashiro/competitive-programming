#include <iostream>
#include <list>
using namespace std;

class CLIP{
		public:
				int first;
				int num;
};

list<CLIP> card;

void divide(int a,int b)
{
		CLIP c;
		list<CLIP>::iterator it=card.begin();
		int n=0;
		for(it;n<a;it++)
				n+=(*it).num;
		it--;
		(*it).num-=(n-a);
		c.first=(*it).first+(*it).num;
		c.num=(n-a);
		it++;
		card.insert(it,c);

		for(it;n<b;it++)
				n+=(*it).num;
		it--;
		(*it).num-=(n-b);
		c.first=(*it).first+(*it).num;
		c.num=(n-b);
		it++;
		card.insert(it,c);
}

void shuffle(int a,int b)
{
		list<CLIP>::iterator ait=card.begin();
		list<CLIP>::iterator bit=card.begin();
		int n=0;
		for(ait;n!=a;ait++)
				n+=(*ait).num;
		bit=ait;
		for(bit;n!=b;bit++)
				n+=(*bit).num;

		//cout  << (*ait).first << "-" << (*ait).num << endl;
		//cout  << (*bit).first << "-" << (*bit).num << endl;

		list<CLIP> l;
		list<CLIP>::iterator it=bit;
		for(it;it!=card.end();it++)
				l.push_back(*it);
		it=ait;
		for(it;it!=bit;it++)
				l.push_back(*it);
		it=card.begin();
		for(it;it!=ait;it++)
				l.push_back(*it);
		card=l;
}

void show()
{
		cout << "show ";
		list<CLIP>::iterator it=card.begin();
		for(it;it!=card.end();it++)
				cout  << (*it).first << "-" << (*it).num << " ";
				//for(int i=(*it).first;i<(*it).first+(*it).num;i++)
						//cout << i << " ";
		cout << endl;
}		

int main()
{
		int n;
		cin >> n;
		CLIP c;
		c.first=1;
		c.num=n;
		card.push_back(c);
		int m,p,q,r;
		cin >> m >> p >> q >> r;
		for(int i=0;i<m;i++){
				int x,y;
				cin >> x >> y;
				//show();
				divide(x,y);
				//show();
				shuffle(x,y);
				//show();
		}
		int count=0;
		int ncard=0;
		list<CLIP>::iterator it=card.begin();
		for(it;it!=card.end();it++){
				for(int i=(*it).first;i<(*it).first+(*it).num;i++){
						ncard++;
						if(p<=ncard && ncard<=q)
								if(i<=r)
										count++;
				}
		}
		cout << count << endl;
		return 0;
}


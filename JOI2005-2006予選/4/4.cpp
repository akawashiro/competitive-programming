#include <iostream>
#include <stack>
using namespace std;

void move(stack<int> s[3],int &before)
{
		if(s[0].top() < s[1].top() && before!=2){
				s[0].push(s[1].top());
				s[1].pop();
				before=1;
		}else if(s[1].top() < s[0].top() && before!=1){
				s[1].push(s[0].top());
				s[0].pop();
				before=2;
		}else if(s[1].top() < s[2].top() && before!=4){
				s[1].push(s[2].top());
				s[2].pop();
				before=3;
		}else if(s[2].top() < s[1].top() && before!=3){
				s[2].push(s[1].top());
				s[1].pop();
				before=4;
		}
}

int main()
{
		int n,m;
		cin >> n >> m;
		stack<int> first[3];
		for(int i=0;i<3;i++){
				int a;
				cin >> a;
				first[i].push(0);
				for(int j=0;j<a;j++){
						int b;
						cin >> b;
						first[i].push(b);
				}
		}
		int r1=15000001;
		int before=-1;
		stack<int> s1[3];
		s1[0].push(0);	s1[1].push(0);	s1[2].push(0);
		for(int i=1;i<=n;i++)
				s1[0].push(i);
		for(int i=0;i<=m;i++){
				if(first[0]==s1[0] && first[1]==s1[1] && first[2]==s1[2]){
						r1=i;
						break;
				}
				move(s1,before);
		}
		int r2=15000001;
		before=-1;
		stack<int> s2[3];
		s2[0].push(0);	s2[1].push(0);	s2[2].push(0);
		for(int i=1;i<=n;i++)
				s2[0].push(i);
		for(int i=0;i<=m;i++){
				if(first[0]==s2[0] && first[1]==s2[1] && first[2]==s2[2]){
						r2=i;
						break;
				}
				move(s2,before);
		}
		if(r1<r2){
				cout << r1 << endl;
		}else if(r2<r1){
				cout << r2 << endl;
		}else if(r1!=15000001){
				cout << r1 << endl;
		}else{
				cout << "-1" << endl;
		}
		return 0;
}



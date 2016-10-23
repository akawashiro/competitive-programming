#include <iostream>
#include <string>
using namespace std;

int main()
{
		int n;
		int dice[6];
		int count=1;
		dice[0]=5;	dice[1]=1;	dice[2]=3;
		dice[3]=6;	dice[4]=4;	dice[5]=2;
		cin >> n;
		for(int i=0;i<n;i++){
				string s;
				cin >> s;
				if(s=="North"){
						int a=dice[0];	dice[0]=dice[1];
						dice[1]=dice[5];	dice[5]=dice[3];
						dice[3]=a;
				}else if(s=="South"){
						int a=dice[0];	dice[0]=dice[3];
						dice[3]=dice[5];	dice[5]=dice[1];
						dice[1]=a;
				}else if(s=="West"){
						int a=dice[1];	dice[1]=dice[2];
						dice[2]=dice[3];	dice[3]=dice[4];
						dice[4]=a;
				}else if(s=="East"){
						int a=dice[1];	dice[1]=dice[4];
						dice[4]=dice[3];	dice[3]=dice[2];
						dice[2]=a;
				}else if(s=="Right"){
						int a=dice[5];	dice[5]=dice[2];
						dice[2]=dice[0];	dice[0]=dice[4];
						dice[4]=a;
				}else if(s=="Left"){
						int a=dice[5];	dice[5]=dice[4];
						dice[4]=dice[0];	dice[0]=dice[2];
						dice[2]=a;
				}
				count+=dice[1];
		}
		cout << count << endl;
		return 0;
}


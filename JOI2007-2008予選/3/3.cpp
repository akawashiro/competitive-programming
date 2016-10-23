#include <iostream>
using namespace std;

int main()
{
		char card[201];
		int tn,hn;
		for(int i=0;i<201;i++)
				card[i]='N';
		int n;
		cin >> n;
		tn=n;	hn=n;
		for(int i=1;i<2*n+1;i++)
				card[i]='H';
		for(int i=0;i<n;i++){
				int a;
				cin >> a;
				
				//cout << a << endl;
				
				card[a]='T';
		}

		//cout << hn << endl << tn << endl;

		int stage=0;
		while(tn!=0 && hn!=0){
				bool istpassed=true;
				for(int i=1;i<2*n+1;i++){
						if(card[i]=='T' && stage<i){
								tn--;
								card[i]='N';
								stage=i;
								istpassed=false;
								break;
						}
				}
				if(istpassed)
						stage=0;

				//cout << stage << endl;

				if(tn==0 || hn ==0)
						break;

				bool ishpassed=true;
				for(int i=1;i<2*n+1;i++){
						if(card[i]=='H' && stage<i){
								hn--;
								card[i]='N';
								stage=i;
								ishpassed=false;
								break;
						}
				}
				if(ishpassed)
						stage=0;

				//cout << stage << endl;
		}

		cout << hn << endl << tn << endl;
		return 0;
}


#include <iostream>
using namespace std;

int product[300];
int a,b,c;
int trouble[1000][3];
int ntrouble=0;

int main()
{
		cin >> a >> b >> c;
		for(int i=0;i<a+b+c;i++)
				product[i]=2;
		int N;
		cin >> N;
		for(int i=0;i<N;i++){
				int d,m,c,r;
				cin >> d >> m >> c >> r;
				if(r==1){
						product[d]=1;
						product[m]=1;
						product[c]=1;
				}else{
						trouble[ntrouble][0]=d;
						trouble[ntrouble][1]=m;
						trouble[ntrouble][2]=c;
						ntrouble++;
				}
		}
		for(int i=0;i<ntrouble;i++){
				if(product[trouble[i][0]]==1 && product[trouble[i][1]]==1){
						product[trouble[i][2]]=0;
				}else if(product[trouble[i][1]]==1 && product[trouble[i][2]]==1){
						product[trouble[i][0]]=0;
				}else if(product[trouble[i][2]]==1 && product[trouble[i][0]]==1){
						product[trouble[i][1]]=0;
				}
		}
		for(int i=0;i<a+b+c;i++)
				cout << product[i] << endl;
		return 0;
}


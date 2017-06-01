#include <iostream>
using namespace std;

int main()
{
		bool senbei[10000][10];
		int R,C;
		int max=0;
		//cin >> R >> C;
		cout << R << " " << C << endl;
		for(int i=0;i<R;i++){
				for(int j=0;j<C;j++){
						int a;
						cin >> a;
						senbei[j][i]=(a==1) ? true : false;
				}
		}
		for(int i=0;i<(1<<R);i++){
				bool cs[C][R];
				int count=0;
				for(int j=0;j<R;j++)
						for(int k=0;k<C;k++)
								cs[k][j]=senbei[k][j];
				for(int j=0;j<R;j++){
						if(i & (1<<j)){
								for(int k=0;k<C;k++)
										cs[k][j]=(cs[k][j]==true) ? false :true;
						}
				}
				/*
				for(int p=0;p<R;p++){
						for(int q=0;q<C;q++)
								cout << cs[q][p] << " ";
						cout << endl;
				}
				cout << endl;
				*/

				for(int j=0;j<C;j++){
						int a=0;
						for(int k=0;k<R;k++)
								if(cs[j][k])
										a++;
						count+=(R-a < a) ? a : (R-a);
				}
				/*
				for(int p=0;p<R;p++){
						for(int q=0;q<C;q++)
								cout << cs[q][p] << " ";
						cout << endl;
				}
				cout << endl;
				*/

			max = (max < count) ? count : max;
		}
		cout << max;
		return 0;
}


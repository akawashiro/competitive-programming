#include <iostream>
using namespace std;
int card[200];
int N;

void cut(int k)
{
		int a[200];
		for(int i=0;i<=N;i++){
				a[i]=card[i];
		}
		for(int i=0;i<k;i++){
				card[N-k+i]=a[i];
		}
		for(int i=k;i<N;i++){
				card[i-k]=a[i];
		}
}

void shuffle()
{	
		int a[200];
		for(int i=0;i<=N;i++){
				a[i]=card[i];
		}

		int i,j;
		i=0;
		j=0;
		while(j<N){
			card[i]=a[j];
			i+=1;
			j+=2;
		}
		j=1;
		while(j<N){
				card[i]=a[j];
				i++;
				j+=2;
		}
}

int main()
{
		int n,m,k;
		cin >> n >> m;
		N=n*2;
		for(int i=0;i<N;i++){
				card[i]=i+1;
		}
		for(int i=0;i<m;i++){
				
				//for(int i=0;i<N;i++)
				//		cout << card[i] << endl;

				cin >> k;
				if(k==0)
						shuffle();
				else
						cut(k);
		}

		for(int i=0;i<N;i++)
				cout << card[i] << endl;
		return 0;
}


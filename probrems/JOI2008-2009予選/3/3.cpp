#include <iostream>
#include <vector>
using namespace std;

int N;

int minchara(int v[10000],int p,int q)
{
		/*for(int i=0;i<N;i++){
				if(v[i]!=-1)
						cout << v[i] << " ";
		}
		cout << endl;*/

		if(v[p]!=v[q]){
				int a=0;
				for(int i=0;i<N;i++)
						if(v[i]!=-1)
								a++;
				return a;
		}

		
		int s,e;
		s=p; e=q;
		while(0<s && v[s-1]==v[p])
				s--;
		while(e<(N-1) && v[e+1]==v[q])
				e++;
		int erased=(p-s+1)+(e-q+1);

		if(4<=erased){
				for(int i=s;i<=p;i++)
						v[i]=-1;
				for(int i=q;i<=e;i++)
						v[i]=-1;
		}
	    if(0!=s && e!=(N-1) && 4<=erased){
				return minchara(v,s-1,e+1);
		}else{
				int a=0;
				for(int i=0;i<N;i++)
						if(v[i]!=-1)
								a++;
				return a;
		}
}

int main()
{
		cin >> N;
		int chara[10000];
		for(int i=0;i<N;i++)
				cin >> chara[i];
		int min=N;
		for(int i=0;i<N;i++){
				int old=chara[i];
				for(int j=1;j<=3;j++){
						if(j!=old){
								chara[i]=j;
								int v[10000];
								for(int k=0;k<N;k++)
										v[k]=chara[k];
								int a;
								if(i!=0){
										a=minchara(v,i-1,i);
								}else if(i!=(N-1)){
										a=minchara(v,i,i+1);
								}
								min=(a<min) ? a : min;
						}
				}
				chara[i]=old;

				/*cout << "c ";
				for(int i=0;i<N;i++){
						if(chara[i]!=-1)
								cout << chara[i] << " ";
				}
				cout << endl;*/

		}
		cout << min << endl;
		return 0;
}

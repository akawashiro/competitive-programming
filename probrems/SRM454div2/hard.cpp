//this is copy
#include <algorithm>
typedef long long LL;

class NumbersAndMatches{
	public:
		LL differentNumbers( long long N, int K )
		{
			const int number[10][7] = {
				{ 1, 1, 1, 1, 1, 0, 1 },    //  0
				{ 0, 1, 0, 1, 0, 0, 1 },    //  1
				{ 0, 1, 1, 0, 1, 1, 1 },    //  2
				{ 0, 1, 0, 1, 1, 1, 1 },    //  3
				{ 1, 1, 0, 1, 0, 1, 0 },    //  4
				{ 1, 0, 0, 1, 1, 1, 1 },    //  5
				{ 1, 0, 1, 1, 1, 1, 1 },    //  6
				{ 0, 1, 0, 1, 1, 0, 0 },    //  7
				{ 1, 1, 1, 1, 1, 1, 1 },    //  8
				{ 1, 1, 0, 1, 1, 1, 1 },    //  9
			};
			struct {int move,int add;} match[10][10];
			for(int i=0;i<10;i++)
				for(int j=0;j<10;j++){
					int a=0,d=0;
					for(int k=0;k<7;k++){
						if(number[i][k]>number[j][k])	d++;
						if(number[i][k]<number[j][k])	a++;
					}
					match[i][j].move=min(d,a);
					move[i][j].add=a-d;
				}
			int digit=0;
			for(LL i=1;i<=N;i*=10)
				digit++;

			LL table[20][130][200];
			memset(table,0,sizeof(table));
			table[0][0][100]=1;
			for(int d=1;d<=digit;d++,N/=10)
				for(int k=0;k<=K;k++)
					for(int a=0;a<200;a++)
						for(int n=0;n<10;n++){
							int tk=match[N%10][n].move+max(match[N%10][n].add,0);
							int ta=match[N%10][n].add;
							if(0<=k-tk && 0<=a-ta && a-ta<200)
								table[d][k][a]+=table[d-1][k-tk][a-ta];
						}
			LL ans=0;
			for(int k=0;k<=K;k++)
				ans+=table[digit][k][100];
			return ans;
		}
};

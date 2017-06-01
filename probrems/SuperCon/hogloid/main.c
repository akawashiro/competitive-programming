/* SuperCon 2011 予選問題Ｃ用テンプレート

   ・解答プログラムはこのテンプレートに従って作成すること．

　 ・解答プログラムは１つのファイルで，チーム名.c という名前にすること．

　 ・入力の方式は，あらかじめ入力ファイル（例：input_sample.txt）を作っ

　　 ておき，実行時にファイル名を指定する方式です．

*/



#include <assert.h>

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <time.h>



/* ↓以下の範囲は変更可能 */

#define INF (1000000)

#define MAX_SIZE (201)

#define MAX_V (MAX_SIZE*MAX_SIZE*4)

#define MAX_K (200)

#define MAX_HEAP (MAX_SIZE*MAX_SIZE*MAX_K*16)

#define REP(cnt,mx) int cnt;for(cnt=0;cnt<(int)mx;++cnt)

#define REPN(cnt,mx,in) for(int cnt=in;cnt<mx;++cnt)

typedef long long lint;

int dx[]={0,1,0,-1},dy[]={1,0,-1,0};

typedef struct{

	int cost;

	int x,y;

	int way;

}vis;

typedef struct{

	int fr,sc;

}pair;



inline void swap(vis* val1,vis* val2){

	const vis tmp=*val1;

	*val1=*val2;

	*val2=tmp;

};



inline int less(const vis* val,const vis* val2){

	if(val->cost!=val2->cost){

		if(val->cost<val2->cost) return 1;

		return 0;

	}

	if(val->x!=val2->x){

		if(val->x<val2->x) return 1;

		return 0;

	}

	if(val->y!=val2->y){

		if(val->y<val2->y) return 1;

		return 0;

	}

	return 0;

};



typedef struct{

	int cnt;

	vis* mem;

}heap;



heap* done;

void heapinit(const int size){

	done->mem=malloc(size);

	done->cnt=1;

	memset(done->mem,-1,sizeof(done->mem));

	done->mem[0]=(vis){-INF,-INF,-INF,-INF};

};



inline void heapdelete(){

	free(done->mem);

};



inline void climb(int pos){

	vis v=done->mem[pos];

	while(less(&v,&done->mem[pos/2])){

		done->mem[pos]=done->mem[pos/2];

		pos/=2;

	}

	done->mem[pos]=v;

}



inline void push(const vis* ins){

	const int c=done->cnt;

	++done->cnt;

	done->mem[c]=*ins;

	climb(c);

}



void down(int pos){

	int son;

	vis v=done->mem[pos];

	while((son=pos*2)<done->cnt){

		if(son+1<done->cnt && less(&done->mem[son+1],&done->mem[son]))

			++son;

		if(less(&done->mem[son],&v)){

			done->mem[son/2]=done->mem[son];

			pos=son;

		}else break;

	}

	done->mem[pos]=v;

};



inline vis top(){

	return done->mem[1];

}



inline void pop(){

	done->mem[1]=done->mem[done->cnt-1];

	--done->cnt;

	down(1);

}



inline int exist(){

	if(done->cnt==1) return 0;

	return 1;

}



pair best[MAX_SIZE][MAX_SIZE][MAX_K];

int reversed_best[MAX_SIZE][MAX_SIZE];

int reversed_visited[MAX_SIZE][MAX_SIZE];

int selectedcnt[MAX_SIZE][MAX_SIZE];

heap q;

heap pq;

/* ↑上記の範囲は変更可能 */



int main(int argc, char** argv) {

  int answer_length = -1; /* この変数に k 番目に長い経路の長さを代入してください */

  int answer_number = -1; /* この変数に k 番目に長い経路の総数を代入してください */

  int m, n, k;

  int D[200+1][200+1][4];

  char* problem_file;

  clock_t start, end;

  FILE* fp;



  int i, x, y;

  char buf[0xffff];

  char* p;



  if (argc <= 1) {

    fprintf(stderr, "Enter the input file.\n");

    exit(EXIT_FAILURE);

  }



  problem_file = argv[1];

  fp = fopen(problem_file, "r");

  if (fp == NULL) {

    fprintf(stderr, "Cannot open %s.\n", problem_file);

    exit(EXIT_FAILURE);

  }



  p = fgets(buf, 0xffff, fp);

  assert(p != 0);



  m = atoi(strtok(buf, ", \n"));

  n = atoi(strtok(NULL, ", \n"));

  k = atoi(strtok(NULL, ", \n"));

  assert(m > 0 && m <= 200);

  assert(n > 0 && n <= 200);

  assert(k > 0 && k <= 200);

  for (y = 0; y <= n; y++) {

    p = fgets(buf, 0xffff, fp);

    assert(p != 0);

    p = strtok(buf, ", \n");

    for (i = 0; i < m; i++) {

      int length = atoi(p);

      assert(length >= 0 && length <= 20);

      D[i][y][1] = length;

      D[i+1][y][3] = length;

      p = strtok(NULL, ", \n");

    }

    D[0][y][3] = 0;

    D[m][y][1] = 0;

  }

  for (x = 0; x <= m; x++) {

    p = fgets(buf, 0xffff, fp);

    assert(p != 0);

    p = strtok(buf, ", \n");

    for (i = 0; i < n; i++) {

      int length = atoi(p);

      assert(length >= 0 && length <= 20);

      D[x][i][0] = length;

      D[x][i+1][2] = length;

      p = strtok(NULL, ", \n");

    }

    D[x][0][2] = 0;

    D[x][n][0] = 0;

  }



  fclose(fp);



  /* 入力した情報を画面に出力する（デバッグ等に使って下さい）

　　 提出時は削除しないで，このようにコメントアウトすること

  printf("The input graph\n");

  for (i = 2*n; i >= 0; i--) {

    y = i / 2;

    if (i % 2 == 0) {

      printf("+");

      for (x = 0; x < m; x++) {

        assert(D[x][y][1] == D[x+1][y][3]);

        printf("%d+", D[x][y][1]);

      }

      assert(D[0][y][3] == 0);

      assert(D[m][y][1] == 0);

    } else if (i > 0) {

      for (x = 0; x <= m; x++) {

        assert(D[x][y][0] == D[x][y+1][2]);

        assert(y != n-1 || D[x][y+1][0] == 0);

        printf("%d ", D[x][y][0]);

      }

    } else {

      for (x = 0; x <= m; x++) {

        assert(D[x][y][2] == 0);

      }

    }

    printf("\n");

  }

  printf("\n");

  */



  /* 時間計測用（デバッグ等に使って下さい）

　　 提出時は削除しないで，このようにコメントアウトすること

  start = clock();

  */



/* ↓以下の範囲は変更可能 */

	++m;++n;

	memset(selectedcnt,0,sizeof(selectedcnt));

	memset(reversed_best,-1,sizeof(reversed_best));

	memset(best,0,sizeof(best));	  

	done=&pq;

	heapinit(MAX_V);

	push(&(vis){0,m-1,n-1,1});

	while(exist()){

		vis cur=top();pop();

		if(reversed_best[cur.y][cur.x]!=-1) continue;

		reversed_best[cur.y][cur.x]=cur.cost;

		REP(j,4){

			int px=dx[j]+cur.x,py=dy[j]+cur.y;

			if(px<0 || py<0 || px>=m || py>=n || D[cur.x][cur.y][j]==0 ||  reversed_best[py][px]!=-1)

				continue;

			push(&(vis){cur.cost+D[cur.x][cur.y][j],px,py,1});

		}

	}

	if(reversed_best[0][0]==-1){

		answer_length=0;

		answer_number=0;

	}else{

	REP(yy,n){

		REP(xx,m){

			REP(j,4){

				if(D[xx][yy][j]!=0){

					int px=dx[j]+xx,py=dy[j]+yy;

					D[xx][yy][j]=D[xx][yy][j]+reversed_best[py][px]-reversed_best[yy][xx];

				}else D[xx][yy][j]=INF;

			}

		}

	}

	heapdelete();

	done=&q;

	heapinit(MAX_HEAP);

	push(&(vis){0,0,0,1});

	while(exist()){

		vis cur=top();pop();

		while(exist()){

			vis nx=top();

			if(nx.x==cur.x && nx.y==cur.y && nx.cost==cur.cost){

				cur.way+=nx.way;

				pop();

			}else break;

		}



		int* c=&selectedcnt[cur.y][cur.x];

		if(*c-1>=0 && best[cur.y][cur.x][*c-1].fr==cur.cost)

			best[cur.y][cur.x][*c-1].sc+=cur.way;

		else{

		if(*c==k) continue;

		best[cur.y][cur.x][*c].sc=cur.way;

		best[cur.y][cur.x][*c].fr=cur.cost;

		++(*c);

		if(*c==k && cur.y==n-1 && cur.x==m-1) break;



		}

		REP(j,4){

			int px=cur.x+dx[j],py=cur.y+dy[j];

			int nxtcost=cur.cost+D[cur.x][cur.y][j];

			if(px>=m || py>=n || px<0 || py<0 ||

				D[cur.x][cur.y][j]==INF ||

				 (selectedcnt[py][px]==k && best[py][px][k-1].fr!=nxtcost) ) continue;

			push(&(vis){nxtcost,px,py,cur.way});

		}

	};

	heapdelete();

	answer_length=best[n-1][m-1][k-1].fr+reversed_best[0][0];

	answer_number=best[n-1][m-1][k-1].sc;

	}

		



/* ↑上記の範囲は変更可能 */





  /* 時間計測用（デバッグ等に使って下さい）

　　 提出時は削除しないで，このようにコメントアウトすること

 */ end = clock();

  printf("%s, %f, %d, %d\n", problem_file, (double)(end - start) / CLOCKS_PER_SEC, answer_length, answer_number);

  



  printf("%s, %d, %d\n", problem_file, answer_length, answer_number);

  return 0;

}

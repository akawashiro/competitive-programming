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

#define W_MAX (201)
#define H_MAX (201)
#define N_MAX (8041)
#define Q_MAX (3200010)
#define max(a,b) (a>b?a:b)

int *memo[W_MAX][H_MAX];
int cost[W_MAX][H_MAX][4];
int begin[W_MAX][H_MAX];
int shortest[W_MAX][H_MAX];
int globalLength;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int qsize;
typedef struct {
  int key;
  int realcost;
  int x,y;
} QUE;
QUE que[Q_MAX+1];

#define PARENT(i) ((i)>>1)
#define LEFT(i)   ((i)<<1)
#define RIGHT(i)  (((i)<<1)+1)

void init(void)
{
  qsize = 0;
}

static void min_heapify(int i)
{
  int l, r;
  int smallest;

  l = LEFT(i), r = RIGHT(i);
  if (l < qsize && que[l].key < que[i].key) smallest = l; else smallest = i;
  if (r < qsize && que[r].key < que[smallest].key) smallest = r;
  if (smallest != i) {
    QUE t = que[i]; que[i] = que[smallest]; que[smallest] = t;
    min_heapify(smallest);
  }
}

int deq(QUE *q)
{
  if (qsize == 0) return 0;
  memcpy(q, &que[0], sizeof(QUE));
  que[0] = que[--qsize];
  min_heapify(0);
  return 1;
}

void enq(QUE *q)
{
  int i, ii;

  i = qsize++;
  memcpy(&que[i], q, sizeof(QUE));
  while (i > 0 && que[ii = PARENT(i)].key > que[i].key) {
    QUE t = que[i]; que[i] = que[ii]; que[ii] = t;
    i = ii;
  }
}


int ksp(int sx, int sy, int gx, int gy, int k) {
  int dist[W_MAX][H_MAX]={{0}};
  int prev[W_MAX][H_MAX];
  int i,key,cst,x,y;
  QUE temp;
  
  init();
  
  temp.key = 0 , temp.realcost = 0 , temp.x = sx , temp.y = sy ;  
  enq(&temp);
  while ( deq(&temp) != 0 ) {
	key = temp.key;
	cst = temp.realcost;
	x = temp.x ;
	y = temp.y ;
		
    if (dist[x][y] >= k || (dist[x][y] >= 1 && prev[x][y] == cst)) continue;
	else{
		dist[x][y]++ , prev[x][y] = cst;
	}
	
	if(dist[x][y] == k && x == gx && y == gy) return cst;
	
	for(i=0;i<4;i++){
		if(cost[x][y][i] != 0){
			temp.x = x+dx[i] , temp.y = y+dy[i];
			temp.key = key + (cost[x][y][i] - shortest[x][y] + shortest[temp.x][temp.y]);
			temp.realcost = cst + cost[x][y][i];
			enq(&temp);
		}
	}
  }
  return 0;
}

int dijkstra(int sx, int sy,int gx,int gy,int save_to[W_MAX][H_MAX]) {
  char done[W_MAX][H_MAX]={{0}};
  int i,c,x,y;
  QUE temp;
  init();  
  temp.key = 0 , temp.x = sx , temp.y = sy;  
  enq(&temp);
  while ( deq(&temp) != 0 ) {
	c = temp.key ;
	x = temp.x ;
	y = temp.y ;
		
    if(done[x][y]) continue;
	else save_to[x][y] = c , done[x][y] = 1;
	
	for(i=0;i<4;i++){
		if(cost[x][y][i] != 0){
			temp.key = c + cost[x][y][i] , temp.x = x+dx[i] , temp.y = y+dy[i];
			enq(&temp);
		}
	}
  }
  return (int)done[gx][gy];
}

int dfs(int x,int y,int c){
	if(c  > globalLength - shortest[x][y]) return 0;
	if(~memo[x][y][ c - begin[x][y] ])return memo[x][y][ c - begin[x][y] ];
	int d, ans = 0;	
	for(d=0;d<4;d++){
		if(cost[x][y][d]){
			ans += cost[x][y][d] ? dfs( x+dx[d] , y+dy[d] , c + cost[x][y][d]) : 0;
		}
	}
	
	return memo[x][y][ c - begin[x][y] ] = ans;
	
}

int total(int m,int n,int answer_length){
	int i,j;
	for(i=0;i<=m;i++)for(j=0;j<=n;j++){
		memo[i][j] = (int *)malloc( sizeof(int) * ( max(0,answer_length - shortest[i][j] - begin[i][j]+1) + 1) );
		memset(memo[i][j] , -1 ,    sizeof(int) * ( max(0,answer_length - shortest[i][j] - begin[i][j]+1) + 1) );
	}
	
	globalLength = answer_length;
	memo[m][n][answer_length - begin[m][n] ] = 1;
	return dfs(0,0,0);
}

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
	memcpy(cost,D,sizeof(cost));
	
	if( dijkstra(m,n,0,0,shortest) ){
		dijkstra(0,0,m,n,begin);
		answer_length = ksp(0,0,m,n,k);
		answer_number = total(m,n,answer_length);
	}else{
		answer_length = 0;
		answer_number = 0;
	}
/* ↑上記の範囲は変更可能 */


  /* 時間計測用（デバッグ等に使って下さい）
　　 提出時は削除しないで，このようにコメントアウトすること
  end = clock();
  printf("%s, %f, %d, %d\n", problem_file, (double)(end - start) / CLOCKS_PER_SEC, answer_length, answer_number);
  */

  printf("%s, %d, %d\n", problem_file, answer_length, answer_number);
  return 0;
}

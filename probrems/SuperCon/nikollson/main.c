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




#define rep(i,n) for(i=0;i<n;i++)


///////// ダイクストラ用のpriority_queue ///////////
struct S{
	unsigned char x,y;
	int c,n;
};
struct S que[1000000];
int quecont=0;

struct S queTop(){return que[0];}

char Scomp(int n,int k){
	if(que[n].n < que[k].n)return 1;
	if(que[n].n > que[k].n)return 0;
	if(que[n].c < que[k].c)return 1;
	return 0;
}

void quePop(){
	int nex=1,bef=0;
	struct S temp;
	
	quecont--; que[0]=que[quecont];
	while(1){
		if(nex>=quecont)break;
		if(nex+1!=quecont && Scomp(nex+1,nex))nex++;
		if(Scomp(nex,bef)){
			temp = que[nex];
			que[nex]=que[bef];
			que[bef]=temp;
		}
		bef = nex; nex = bef*2+1;
	}
}

void quePush(struct S a){
	int nex=(quecont-1)/2, bef=quecont;
	struct S temp;
	
	que[quecont]=a;
	
	while(1){
		if(bef==0 || Scomp(nex,bef))break;
		temp = que[nex];
		que[nex]=que[bef];
		que[bef]=temp;
		bef = nex;
		nex = (bef-1)/2;
	}
	quecont++;
}

////そのマスの現時点での同経路長毎に、経路数を保存するための循環配列//////

int  qum[202][202][64]={0};
unsigned short befq[202][202][64]={0};
int sumqPush(unsigned char x,unsigned char y,int n,int c){
	int nn = n%64;
	if(befq[x][y][nn]==n/64+1){
		qum[x][y][nn]+=c;
		return 1;
	}
	else{
		qum[x][y][nn]=c;
		befq[x][y][nn]=n/64+1;
	}
	return 0;
}
int sumqPop(unsigned char x,unsigned char y,int n){
	int nn = n%64;
	if(befq[x][y][nn]!=n/64+1)return 0;
	return qum[x][y][nn];
}

////////////////////ゴールから全点へDijkstra////////////////////

int shota[202][202];
int fvisit[202][202]={0};
void firstDijkstra(unsigned char h,unsigned char w,int masu[201][201][4]){
	struct S u,e;
	unsigned char p,dx,dy;
	
	quecont=0;
	e.x=h; e.y=w; e.c=0; e.n=0;
	quePush(e);
	while(1){
		if(quecont==0)break;
		u = queTop();
		quePop();	
		
		if(fvisit[u.x][u.y]==1)continue;
		fvisit[u.x][u.y]=1;
		
		shota[u.x][u.y]=u.n;
		
		rep(p,4){
			if(p==3){dx=-1; dy=0;}else
			if(p==0){dx=0; dy=1;}else
			if(p==1){dx=1; dy=0;}else
			if(p==2){dx=0; dy=-1;}
			
			if(masu[u.x][u.y][p]==0)continue;
			e.x = u.x + dx;
			e.y = u.y + dy;
			e.n = u.n + masu[u.x][u.y][p];
			
			quePush(e);
		}
	}
	quecont=0;
}

////////////////答えをポインタに代入する関数///////////////

int viscon[202][202]={0};
void solve(int h,int w,int k,int masu[201][201][4] ,int* ans1,int* ans2){
	int i,j,t,time,aaa;
	char dx,dy,v,p;
	struct S u,e;
	
	int ansval[202];
	int ansvaf[202]={0};
	int acont=0;
	
	
	firstDijkstra(h,w,masu);
	
	
	if(shota[0][0]==0){
		*ans1 = 0;
		*ans2 = 0;
		return;
	}
	
	e.x=0; e.y=0; e.c=0; e.n = e.c+shota[0][0];
	quePush(e);
	sumqPush(0,0,e.n,1);
	
	while(1){
		if(quecont==0){break;}
		
		u = queTop();
		quePop();
		
		if(u.x<0 || u.y<0 || u.x>=h+2 || u.y>=w+2)continue;
		if(viscon[u.x][u.y]>k)continue;
		
		t = sumqPop(u.x,u.y,u.n);
		if(t==0)continue;
		
		viscon[u.x][u.y]++;
		
		if(u.x == h && u.y == w){
			ansval[acont]=u.n;
			ansvaf[acont]=t;
			acont++;
			if(viscon[u.x][u.y]>=k)break;
		}
		
		
		rep(p,4){
			if(p==3){dx=-1; dy=0;}else
			if(p==0){dx=0; dy=1;}else
			if(p==1){dx=1; dy=0;}else
			if(p==2){dx=0; dy=-1;}
			
			if(masu[u.x][u.y][p]==0)continue;
			e.x = u.x + dx;
			e.y = u.y + dy;
			e.c = u.c + masu[u.x][u.y][p];
			e.n = e.c + shota[e.x][e.y];
			v=sumqPush(e.x,e.y,e.n,t);
			
			if(v==0)quePush(e);
		}
	}
	
	*ans1 = ansval[acont-1];
	*ans2 = ansvaf[acont-1];
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
        printf("%2d +", D[x][y][1]);
      }
      assert(D[0][y][3] == 0);
      assert(D[m][y][1] == 0);
    } else if (i > 0) {
      for (x = 0; x <= m; x++) {
        assert(D[x][y][0] == D[x][y+1][2]);
        assert(y != n-1 || D[x][y+1][0] == 0);
        printf("%2d  ", D[x][y][0]);
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

	solve(m,n,k,D ,&answer_length ,&answer_number);

/* ↑上記の範囲は変更可能 */


  /* 時間計測用（デバッグ等に使って下さい）
　　 提出時は削除しないで，このようにコメントアウトすること
  end = clock();
  printf("%s, %f, %d, %d\n", problem_file, (double)(end - start) / CLOCKS_PER_SEC, answer_length, answer_number);
  */

  printf("%s, %d, %d\n", problem_file, answer_length, answer_number);
  return 0;
}


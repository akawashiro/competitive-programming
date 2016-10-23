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

#include <stdbool.h>

int ve[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int minkD[200+1][200+1][200]; //k番目に小さいパスの長さ
int minkV[200+1][200+1][200]; //k番目に小さいパスの数

int DD[200+1][200+1][4];
int M,N,K;

int solve(int nowx,int nowy,int nowk){
    if(minkV[nowx][nowy][nowk]==-1){
        minkV[nowx][nowy][nowk]=0;
        for(int v=0;v<4;v++){
            if(DD[nowx][nowy][v]==0) continue;
            int nextx=nowx+ve[v][0],nexty=nowy+ve[v][1];
            if(nextx<0 || nextx>M|| nexty<0 || nexty>N) continue;
            for(int i=0;i<K;i++){
                if(minkD[nextx][nexty][i]+DD[nowx][nowy][v]==minkD[nowx][nowy][nowk]){
                    minkV[nowx][nowy][nowk]+=solve(nextx,nexty,i);
                    break;
                }
            }
        }
    }
    return minkV[nowx][nowy][nowk];
}

typedef struct Path{
    int x,y,d;
}Path;

bool pathcomp(Path a,Path b){
    if(a.d>b.d)return true;
    else if(a.d==b.d){
        if(a.x>b.x) return true;
        else if(a.x==b.x){
            if(a.y>=b.y) return true;
            else return false;
        }else return false;
    }else return false;
}
Path path(int d,int x,int y){
    Path ret;
    ret.d=d;
    ret.x=x;
    ret.y=y;
    return ret;
}

int heapsize=0,heapmemsize=0;
Path *heap;
void heap_insert(Path pa){
    heapsize++;
    if(heapmemsize==0){
        heapmemsize=1024;
        heap=(Path*)malloc(sizeof(Path)*heapmemsize);
    }else if(heapsize>heapmemsize){
        heapmemsize*=2;
        Path *t=(Path*)malloc(sizeof(Path)*heapmemsize);
        for(int i=0;i<heapsize;i++){
            t[i]=heap[i];
        }
        free(heap);
        heap=t;
    }
    heap[heapsize-1]=pa;
    int now=heapsize-1;
    while(now>0){
        if(pathcomp(heap[now>>1],heap[now])){ //heap[now/2] > heap[now] のとき
            Path t=heap[now>>1];
            heap[now>>1]=heap[now];
            heap[now]=t;
        }else break;
        now>>=1;
    }
}
Path heap_pop(){
    Path ret=heap[0];
    Path x=heap[heapsize-1];
    int now=0;
    int ne1,ne2;
    while((now<<1)+1<heapsize){
        ne1=(now<<1)+1,ne2=ne1+1;
        if(ne2<heapsize&&pathcomp(heap[ne1],heap[ne2])) ne1=ne2;
        if(pathcomp(x,heap[ne1])){
            heap[now]=heap[ne1];
            now=ne1;
        }else break;
    }
    heap[now]=x;
    heapsize--;
    return ret;
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

    int j,kk,nowx,nowy,nowd,v,nextx,nexty,nextd,*nextdisp,*nextvalp,st,en,t,wari;
    wari=(k-1)/16;
    Path now;

    M=m;
    N=n;
    K=k;

    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            for(kk=0;kk<4;kk++){
                DD[i][j][kk]=D[i][j][kk];
            }
            for(kk=0;kk<200;kk++){
                minkD[i][j][kk]=-1;
                minkV[i][j][kk]=-1;
            }
        }
    }

    minkD[0][0][0]=0;
    minkV[0][0][0]=1;


    heap_insert(path(0,0,0));
    while(heapsize>0){
        Path now=heap_pop();
        nowx=now.x,nowy=now.y,nowd=now.d;
        if(minkD[nowx][nowy][k-1]!=-1 && minkD[nowx][nowy][k-1] < nowd) continue;
        for(v=0;v<4;v++){
            if(D[nowx][nowy][v]==0) continue;
            nextx=nowx+ve[v][0],nexty=nowy+ve[v][1];
            if(nextx<0 || nextx>m || nexty<0 || nexty>n) continue;
            nextd=nowd+D[nowx][nowy][v];
            nextdisp=minkD[nextx][nexty];
            if(nextdisp[k-1]!=-1 && nextdisp[k-1] < nextd) continue;

            if(nextdisp[wari]==-1||nextdisp[wari]>=nextd){
                st=0;
                en=wari;
            }else if(nextdisp[wari*2]==-1||nextdisp[wari*2]>=nextd){
                st=wari*1+1;
                en=wari*2;
            }else if(nextdisp[wari*3]==-1||nextdisp[wari*3]>=nextd){
                st=wari*2+1;
                en=wari*3;
            }else if(nextdisp[wari*4]==-1||nextdisp[wari*4]>=nextd){
                st=wari*3+1;
                en=wari*4;
            }else if(nextdisp[wari*5]==-1||nextdisp[wari*5]>=nextd){
                st=wari*4+1;
                en=wari*5;
            }else if(nextdisp[wari*6]==-1||nextdisp[wari*6]>=nextd){
                st=wari*5+1;
                en=wari*6;
            }else if(nextdisp[wari*7]==-1||nextdisp[wari*7]>=nextd){
                st=wari*6+1;
                en=wari*7;
            }else if(nextdisp[wari*8]==-1||nextdisp[wari*8]>=nextd){
                st=wari*7+1;
                en=wari*8;
            }else if(nextdisp[wari*9]==-1||nextdisp[wari*9]>=nextd){
                st=wari*8+1;
                en=wari*9;
            }else if(nextdisp[wari*10]==-1||nextdisp[wari*10]>=nextd){
                st=wari*9+1;
                en=wari*10;
            }else if(nextdisp[wari*11]==-1||nextdisp[wari*11]>=nextd){
                st=wari*10+1;
                en=wari*11;
            }else if(nextdisp[wari*12]==-1||nextdisp[wari*12]>=nextd){
                st=wari*11+1;
                en=wari*12;
            }else if(nextdisp[wari*13]==-1||nextdisp[wari*13]>=nextd){
                st=wari*12+1;
                en=wari*13;
            }else if(nextdisp[wari*14]==-1||nextdisp[wari*14]>=nextd){
                st=wari*13+1;
                en=wari*14;
            }else if(nextdisp[wari*15]==-1||nextdisp[wari*15]>=nextd){
                st=wari*14+1;
                en=wari*15;
            }else{
                st=wari*15+1;
                en=k-1;
            }

            if(st>en){
                t=st;
                st=en;
                en=t;
            }

            for(i=st;i<=en;i++){
                if(nextdisp[i]==-1){
                    nextdisp[i]=nextd;
                    heap_insert(path(nextd,nextx,nexty));
                    break;
                }else if(nextdisp[i]==nextd) break;
                else if(nextdisp[i]>nextd){
                    for(int j=k-1;j>=i+1;j--){
                        nextdisp[j]=nextdisp[j-1];
                    }
                    nextdisp[i]=nextd;
                    heap_insert(path(nextd,nextx,nexty));
                    break;
                }
            }
        }
    }

    free(heap);

    if(minkD[m][n][k-1]==-1) answer_length=0;
    else answer_length=minkD[m][n][k-1];
    answer_number=solve(m,n,k-1);

/* ↑上記の範囲は変更可能 */


  /* 時間計測用（デバッグ等に使って下さい）
　　 提出時は削除しないで，このようにコメントアウトすること
end = clock();
printf("%s, %f, %d, %d\n", problem_file, (double)(end - start) / CLOCKS_PER_SEC, answer_length, answer_number);
*/

  printf("%s, %d, %d\n", problem_file, answer_length, answer_number);
  return 0;
}

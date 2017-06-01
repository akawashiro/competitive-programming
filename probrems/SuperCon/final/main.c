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

#include <limits.h>

#define HEAPTABLESIZE 4*210*210*210

int heapData[HEAPTABLESIZE];
int heapTable[HEAPTABLESIZE][3];
int heapSize=0;
int heapTableSize=HEAPTABLESIZE;
int heapTableCur=0;

void heapPop(int*,int*,int*);
void heapPush(int,int,int);
int heapEmpty();

void heapDown(int);
void heapUp(int);

int rec(int x,int y,int o);
void solve(int _h,int _w,int _k,int *ans_len,int *ans_num);

int k,w,h;
int mv[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int dist[210][210][210];
int filled[210][210];
int MAP[200+1][200+1][4];
int cache[210][210][210];

int heapEmpty()
{
	return (heapSize==0);
}

void heapPop(int *c,int *x,int *y)
{
	if(heapSize==0)
	{
		*c=-1,*x=-1,*y=-1;
	}
	else if(heapSize==1)
	{
		int r=heapData[1];
		heapData[heapSize]=-1;
		heapSize=0;
		*c=heapTable[r][0],*x=heapTable[r][1],*y=heapTable[r][2];
	}
	else
	{
		int r=heapData[1];
		heapData[1]=heapData[heapSize];
		heapSize--;
		heapDown(1);
		*c=heapTable[r][0],*x=heapTable[r][1],*y=heapTable[r][2];
	}
}

void heapPush(int c,int x,int y)
{
	heapTableCur=(heapTableCur+1)%heapTableSize;
	heapTable[heapTableCur][0]=c;
	heapTable[heapTableCur][1]=x;
	heapTable[heapTableCur][2]=y;

	heapSize++;
	heapData[heapSize]=heapTableCur;

	heapUp(heapSize);
}

void heapUp(int k)
{
	int p=k/2;
	if(k==1)
		;
	else if(heapTable[heapData[k]][0]<heapTable[heapData[p]][0])
	{
		int t=heapData[k];
		heapData[k]=heapData[p];
		heapData[p]=t;
		heapUp(p);
	}
	else
		;
}

void heapDown(int k)
{
	int n1=2*k,n2=2*k+1;
	if(heapSize<n1)
	{
		;
	}
	else if(heapSize<n2)
	{
		if(heapTable[heapData[n1]][0]<heapTable[heapData[k]][0])
		{
			int t=heapData[k];
			heapData[k]=heapData[n1];
			heapData[n1]=t;
			heapDown(n1);
		}
		else
		{
			;
		}
	}
	else
	{
		if(heapTable[heapData[n1]][0]<heapTable[heapData[n2]][0] && 
				heapTable[heapData[n1]][0]<heapTable[heapData[k]][0])
		{
			int t=heapData[k];
			heapData[k]=heapData[n1];
			heapData[n1]=t;
			heapDown(n1);
		}
		else if(heapTable[heapData[n2]][0]<=heapTable[heapData[n1]][0] && 
				heapTable[heapData[n2]][0]<heapTable[heapData[k]][0])
		{
			int t=heapData[k];
			heapData[k]=heapData[n2];
			heapData[n2]=t;
			heapDown(n2);
		}
		else
		{
			;
		}
	}	
}

int rec(int x,int y,int o)
{
	int pp;

	int *r=&cache[x][y][o];
	if(*r!=-1)
		;
	else if(x==0 && y==0 && o==0)
		*r=1;
	else
	{
		*r=0;
		for(pp=0;pp<4;pp++)
			if(MAP[x][y][pp]!=0)
			{
				int xx=x+mv[pp][0],yy=y+mv[pp][1];
				int cc=dist[x][y][o]-MAP[x][y][pp];
				int bo=0,ce=k-1;
				while(1<ce-bo)
				{
					int me=(bo+ce)/2;
					if(dist[xx][yy][me]<cc)
						bo=me;
					else
						ce=me;
				}
				if(dist[xx][yy][bo]==cc)
					*r+=rec(xx,yy,bo);
				else if(dist[xx][yy][ce]==cc)
					*r+=rec(xx,yy,ce);
				else
					;
			}
	}
	return *r;
}

void solve(int _h,int _w,int _k,int *ans_len,int *ans_num)
{
	int pp,qq,rr;
	int c,x,y;
	int cc,xx,yy;

	k=_k,w=_w,h=_h;
	h++,w++;

	for(pp=0;pp<210;pp++)
		for(qq=0;qq<210;qq++)
		{
			for(rr=0;rr<210;rr++)
				dist[pp][qq][rr]=INT_MAX;
			filled[pp][qq]=0;
		}

	heapPush(0,0,0);

	while(!heapEmpty())
	{
		heapPop(&c,&x,&y);

		if(filled[x][y]==k ||
			 	(0<filled[x][y] && dist[x][y][filled[x][y]-1]==c))
		{
			;
		}
		else
		{
			dist[x][y][filled[x][y]]=c;
			filled[x][y]++;

			//if(x!=w-1 || y!=h-1)
				for(pp=0;pp<4;pp++)
					if(MAP[x][y][pp]!=0)
					{
						cc=c+MAP[x][y][pp];
						xx=x+mv[pp][0];
						yy=y+mv[pp][1];

						//if(!(filled[xx][yy]==k || (0<filled[xx][yy] && dist[xx][yy][filled[xx][yy]-1]==cc)))
						//{
							heapPush(cc,xx,yy);
						//}
					}
		}
	}

	memset(cache,-1,sizeof(cache));
	if(dist[w-1][h-1][k-1]!=INT_MAX)
	{
		*ans_len=dist[w-1][h-1][k-1];
		*ans_num=rec(w-1,h-1,k-1);
	}
	else
	{
		*ans_len=0;
		*ans_num=0;
	}
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
	int pp,qq,rr;
	for(pp=0;pp<201;pp++)
		for(qq=0;qq<201;qq++)
			for(rr=0;rr<4;rr++)
				MAP[pp][qq][rr]=D[pp][qq][rr];
	solve(n,m,k,&answer_length,&answer_number);

/* ↑上記の範囲は変更可能 */


  /* 時間計測用（デバッグ等に使って下さい）
　　 提出時は削除しないで，このようにコメントアウトすること
  end = clock();
  printf("%s, %f, %d, %d\n", problem_file, (double)(end - start) / CLOCKS_PER_SEC, answer_length, answer_number);
  */

  printf("%s, %d, %d\n", problem_file, answer_length, answer_number);
  return 0;
}


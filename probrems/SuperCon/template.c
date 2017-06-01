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
　　 提出時は削除しないで，このようにコメントアウトすること*/
  start = clock();
  /**/

/* ↓以下の範囲は変更可能 */

/* ↑上記の範囲は変更可能 */


  /* 時間計測用（デバッグ等に使って下さい）
　　 提出時は削除しないで，このようにコメントアウトすること
  end = clock();
  printf("%s, %f, %d, %d\n", problem_file, (double)(end - start) / CLOCKS_PER_SEC, answer_length, answer_number);
  */

  printf("%s, %d, %d\n", problem_file, answer_length, answer_number);
  return 0;
}

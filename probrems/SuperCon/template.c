/* SuperCon 2011 �\�I���b�p�e���v���[�g
   �E�𓚃v���O�����͂��̃e���v���[�g�ɏ]���č쐬���邱�ƁD
�@ �E�𓚃v���O�����͂P�̃t�@�C���ŁC�`�[����.c �Ƃ������O�ɂ��邱�ƁD
�@ �E���͂̕����́C���炩���ߓ��̓t�@�C���i��Finput_sample.txt�j�����
�@�@ �Ă����C���s���Ƀt�@�C�������w�肷������ł��D
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* ���ȉ��͈͕̔͂ύX�\ */

/* ����L�͈͕̔͂ύX�\ */

int main(int argc, char** argv) {
  int answer_length = -1; /* ���̕ϐ��� k �Ԗڂɒ����o�H�̒����������Ă������� */
  int answer_number = -1; /* ���̕ϐ��� k �Ԗڂɒ����o�H�̑����������Ă������� */
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

  /* ���͂���������ʂɏo�͂���i�f�o�b�O���Ɏg���ĉ������j
�@�@ ��o���͍폜���Ȃ��ŁC���̂悤�ɃR�����g�A�E�g���邱��
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

  /* ���Ԍv���p�i�f�o�b�O���Ɏg���ĉ������j
�@�@ ��o���͍폜���Ȃ��ŁC���̂悤�ɃR�����g�A�E�g���邱��*/
  start = clock();
  /**/

/* ���ȉ��͈͕̔͂ύX�\ */

/* ����L�͈͕̔͂ύX�\ */


  /* ���Ԍv���p�i�f�o�b�O���Ɏg���ĉ������j
�@�@ ��o���͍폜���Ȃ��ŁC���̂悤�ɃR�����g�A�E�g���邱��
  end = clock();
  printf("%s, %f, %d, %d\n", problem_file, (double)(end - start) / CLOCKS_PER_SEC, answer_length, answer_number);
  */

  printf("%s, %d, %d\n", problem_file, answer_length, answer_number);
  return 0;
}

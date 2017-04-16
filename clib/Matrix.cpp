
typedef double number;
const number eps = 1e-8;
typedef vector<number> mat_array;
typedef vector<mat_array> mat_matrix;

// O( n )
mat_matrix identity(int n) {
  mat_matrix A(n, mat_array(n));
  for (int i = 0; i < n; ++i) A[i][i] = 1;
  return A;
}
// O( n )
number inner_product(const mat_array &a, const mat_array &b) {
  number ans = 0;
  for (int i = 0; i < a.size(); ++i)
    ans += a[i] * b[i];
  return ans;
}
// O( n^2 )
mat_array mul(const mat_matrix &A, const mat_array &x) {
  mat_array y(A.size());
  for (int i = 0; i < A.size(); ++i)
    for (int j = 0; j < A[0].size(); ++j)
      y[i] += A[i][j] * x[j];
  return y;
}
// O( n^3 )
mat_matrix mul(const mat_matrix &A, const mat_matrix &B) {
  mat_matrix C(A.size(), mat_array(B[0].size()));
  for (int i = 0; i < C.size(); ++i)
    for (int j = 0; j < C[i].size(); ++j)
      for (int k = 0; k < A[i].size(); ++k)
        C[i][j] += A[i][k] * B[k][j];
  return C;
}
// O( n^3 log e )
mat_matrix pow(const mat_matrix &A, int e) {
  return e == 0 ? identity(A.size())  :
     e % 2 == 0 ? pow(mul(A, A), e/2) : mul(A, pow(A, e-1));
}
// O( n^3 )
number det(mat_matrix A) {
  const int n = A.size();
  number D = 1;
  for (int i = 0; i < n; ++i) {
    int pivot = i;
    for (int j = i+1; j < n; ++j)
      if (abs(A[j][i]) > abs(A[pivot][i])) pivot = j;
    swap(A[pivot], A[i]);
    D *= A[i][i] * (i != pivot ? -1 : 1);
    if (abs(A[i][i]) < eps) break;
    for(int j = i+1; j < n; ++j)
      for(int k = n-1; k >= i; --k)
        A[j][k] -= A[i][k] * A[j][i] / A[i][i];
  }
  return D;
}
// O(n)
number tr(const mat_matrix &A) {
  number ans = 0;
  for (int i = 0; i < A.size(); ++i)
    ans += A[i][i];
  return ans;
}
// O( n^3 ).
int rank(mat_matrix A) {
  const int n = A.size(), m = A[0].size();
  int r = 0;
  for (int i = 0; r < n && i < m; ++i) {
    int pivot = r;
    for (int j = r+1; j < n; ++j)
      if (abs(A[j][i]) > abs(A[pivot][i])) pivot = j;
    swap(A[pivot], A[r]);
    if (abs(A[r][i]) < eps) continue;
    for (int k = m-1; k >= i; --k)
      A[r][k] /= A[r][i];
    for(int j = r+1; j < n; ++j)
      for(int k = i; k < m; ++k)
        A[j][k] -= A[r][k] * A[j][i];
    ++r;
  }
  return r;
}


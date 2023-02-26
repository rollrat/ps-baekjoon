#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;

  int I[1001];

  int A[1001];
  int Ai[1001];

  int Ax = 0, Aix = 0;

  int L[1001];
  int Li[1001];

  for (int i = 0; i < N; i++) {
    int x;
    cin >> I[i];
  }

  for (int i = 0; i < N; i++) {
    if (Ax == 0 || A[Ax - 1] < I[i]) {
      A[Ax++] = I[i];
    } else {
      *lower_bound(A, A + Ax, I[i]) = I[i];
    }

    if (Aix == 0 || Ai[Aix - 1] < I[N - i - 1]) {
      Ai[Aix++] = I[N - i - 1];
    } else {
      *lower_bound(Ai, Ai + Aix, I[N - i - 1]) = I[N - i - 1];
    }

    L[i] = Ax;
    Li[N - i - 1] = Aix;
  }

  int m = 0;

  for (int i = 0; i < N; i++) {
    m = max(m, L[i] + Li[i] - 1);
  }

  cout << m;

  return 0;
}
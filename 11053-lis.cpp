#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;

  int A[1001];
  int j = 0;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;

    if (j == 0 || A[j - 1] < x)
      A[j++] = x;
    else {
      *lower_bound(A, A + j, x) = x;
    }
  }

  cout << j;
}
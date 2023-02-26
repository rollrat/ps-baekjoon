#include <algorithm>
#include <iostream>

using namespace std;

int A[1001];
int N;

int dp[1001];

int dfs(int d) {
  if (dp[d] != 0)
    return dp[d];

  int ret = 1;

  for (int i = d + 1; i < N; i++) {
    if (A[d] < A[i])
      ret = max(ret, dfs(i) + 1);
  }

  return dp[d] = ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int m = 0;

  for (int i = 0; i < N; i++) {
    m = max(m, dfs(i));
  }

  cout << m;

  return 0;
}
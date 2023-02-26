#include <iostream>

using namespace std;

int s[10001];
int dp[10001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> s[i];

  dp[0] = s[0];
  dp[1] = s[0] + s[1];
  dp[2] = max(s[0], s[1]) + s[2];

  for (int i = 3; i < n; i++) {
    dp[i] = max(dp[i - 3] + s[i - 1] + s[i], dp[i - 2] + s[i]);
  }

  cout << dp[n - 1];
}
#include <iostream>

using namespace std;

int dp[101][101][101];

int w(int a, int b, int c) {
  if (dp[a + 50][b + 50][c + 50] > 0)
    return dp[a + 50][b + 50][c + 50];

  if (a <= 0 || b <= 0 || c <= 0)
    return 1;

  if (a > 20 || b > 20 || c > 20)
    return w(20, 20, 20);

  if (a < b && b < c)
    return dp[a + 50][b + 50][c + 50] =
               w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);

  return dp[a + 50][b + 50][c + 50] = w(a - 1, b, c) + w(a - 1, b - 1, c) +
                                      w(a - 1, b, c - 1) -
                                      w(a - 1, b - 1, c - 1);
}

int main() {
  while (true) {
    int a, b, c;

    cin >> a >> b >> c;

    if (a == -1 && b == -1 && c == -1)
      break;

    cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
  }
}
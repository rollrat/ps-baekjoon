#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M;
  cin >> N >> M;

  int d[100][100];

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      d[i][j] = i == j ? 0 : 1e9;

  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    d[a - 1][b - 1] = min(d[a - 1][b - 1], c);
  }

  for (int k = 0; k < N; k++)
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][i]);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      cout << d[i][j] << ' ';
    cout << '\n';
  }
}
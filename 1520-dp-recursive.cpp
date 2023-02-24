#include <iostream>

using namespace std;

int map[500][500];
int dp[500][500];
int M, N;

int dfs(int x, int y) {
  if (y == M - 1 && x == N - 1)
    return 1;

  if (dp[y][x] != -1)
    return dp[y][x];

  int path_count = 0;
  const int d[4] = {0, 0, -1, 1};

  for (int i = 0; i < 4; i++) {
    int dx = x + d[i];
    int dy = y + d[3 - i];

    if (dx >= 0 && dy >= 0 && dx < N && dy < M)
      if (map[dy][dx] < map[y][x])
        path_count += dfs(dx, dy);
  }

  return dp[y][x] = path_count;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> M >> N;

  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++) {
      cin >> map[i][j];
      dp[i][j] = -1;
    }

  cout << dfs(0, 0);
}
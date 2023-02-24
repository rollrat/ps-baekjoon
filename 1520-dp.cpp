#include <iostream>
#include <vector>

using namespace std;

int map[500][500];
int dp[500][500];
vector<pair<int, int>> cost_pos[10001];

int d[4] = {0, 0, 1, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int M, N;
  cin >> M >> N;

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> map[i][j];
      cost_pos[map[i][j]].push_back({i, j});
    }
  }

  dp[0][0] = 1;

  for (int cost = 10000; cost >= 0; cost--) {
    for (auto &p : cost_pos[cost]) {
      for (int i = 0; i < 4; i++) {
        int dx = p.second + d[i];
        int dy = p.first + d[3 - i];

        if (dx >= 0 && dy >= 0 && dx < N && dy < M &&
            map[dy][dx] < map[p.first][p.second]) {
          dp[dy][dx] += dp[p.first][p.second];
        }
      }
    }
  }

  cout << dp[M - 1][N - 1];
}
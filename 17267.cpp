#include <iostream>
#include <queue>

using namespace std;

int map[1001][1001];
bool visit[1001][1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;

  int L, R;
  cin >> L >> R;

  queue<pair<pair<int, int>, pair<int, int>>> q;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      char c;
      cin >> c;

      map[i][j] = c;

      if (c == '2') {
        visit[i][j] = true;
        q.push({{i, j}, {L, R}});
      }
    }
  }

  int cnt = 1;

  while (!q.empty()) {
    auto p = q.front();
    q.pop();

    // vertical up
    for (int i = p.first.first - 1; i >= 0; i--) {
      if (map[i][p.first.second] == '1')
        break;
      if (!visit[i][p.first.second]) {
        q.push({{i, p.first.second}, {p.second.first, p.second.second}});
        visit[i][p.first.second] = true;
        cnt++;
      }
    }

    // vertical down
    for (int i = p.first.first + 1; i < N; i++) {
      if (map[i][p.first.second] == '1')
        break;
      if (!visit[i][p.first.second]) {
        q.push({{i, p.first.second}, {p.second.first, p.second.second}});
        visit[i][p.first.second] = true;
        cnt++;
      }
    }

    // left
    if (p.second.first > 0 && p.first.second >= 1 &&
        map[p.first.first][p.first.second - 1] != '1' &&
        !visit[p.first.first][p.first.second - 1]) {
      q.push({{p.first.first, p.first.second - 1},
              {p.second.first - 1, p.second.second}});
      visit[p.first.first][p.first.second - 1] = true;
      cnt++;
    }

    // right
    if (p.second.second > 0 && p.first.second < M - 1 &&
        map[p.first.first][p.first.second + 1] != '1' &&
        !visit[p.first.first][p.first.second + 1]) {
      q.push({{p.first.first, p.first.second + 1},
              {p.second.first, p.second.second - 1}});
      visit[p.first.first][p.first.second + 1] = true;
      cnt++;
    }
  }

  cout << cnt;
}
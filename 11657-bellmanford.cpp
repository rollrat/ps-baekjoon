#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M;
  cin >> N >> M;

  vector<pair<int, int>> adj[500];
  long long dist[500];

  for (int i = 0; i < M; i++) {
    int A, B, C;
    cin >> A >> B >> C;

    adj[A - 1].push_back({B - 1, C});
  }

  fill(dist, dist + N, 1e18);

  dist[0] = 0;

  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N; j++) {
      for (auto &p : adj[j]) {
        if (dist[j] != 1e18 && dist[p.first] > dist[j] + p.second)
          dist[p.first] = dist[j] + p.second;
      }
    }
  }

  for (int j = 0; j < N; j++) {
    for (auto &p : adj[j]) {
      if (dist[j] != 1e18 && dist[p.first] > dist[j] + p.second) {
        cout << -1;
        return 0;
      }
    }
  }

  for (int i = 1; i < N; i++) {
    if (dist[i] != 1e18)
      cout << dist[i] << '\n';
    else
      cout << "-1\n";
  }
}
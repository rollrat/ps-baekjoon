#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int>> M[801];
long long length[801];

long long shortest_path(int i, int j) {
  if (i == j)
    return 0;

  priority_queue<pair<int, int>> pq;
  fill(length, length + 801, 0x7fffffff);

  for (auto &p : M[i]) {
    pq.push({-p.second, p.first});
  }

  while (!pq.empty()) {
    auto p = pq.top();
    pq.pop();

    if (p.second == j)
      return -p.first;

    if (length[p.second] <= -p.first)
      continue;

    length[p.second] = -p.first;

    for (auto &pp : M[p.second]) {
      if (length[pp.first] > pp.second - p.first)
        pq.push({p.first - pp.second, pp.first});
    }
  }

  return length[j];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, E;
  cin >> N >> E;

  for (int i = 0; i < E; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    M[a].push_back({b, c});
    M[b].push_back({a, c});
  }

  int v1, v2;
  cin >> v1 >> v2;

  long long vv = shortest_path(v1, v2);
  long long x = shortest_path(1, v1);
  long long y = shortest_path(N, v1);
  long long xx = shortest_path(1, v2);
  long long yy = shortest_path(N, v2);

  long long res = vv + min(x + yy, y + xx);

  if (vv >= 0x7fffffff || res >= 0x7fffffff)
    cout << -1;
  else
    cout << res;
}
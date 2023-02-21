#include <iostream>
#include <queue>

using namespace std;

vector<pair<int, int>> M[10001];

bool Visit[10001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int V, E;
  cin >> V >> E;

  for (int i = 0; i < E; i++) {
    int A, B, C;
    cin >> A >> B >> C;

    M[A].push_back({B, C});
    M[B].push_back({A, C});
  }

  priority_queue<pair<int, int>> pq;

  pq.push({0, 1});

  long long cost = 0;

  while (!pq.empty()) {
    auto p = pq.top();
    pq.pop();

    if (Visit[p.second])
      continue;

    Visit[p.second] = true;

    cost += -p.first;

    for (auto &pp : M[p.second]) {
      if (Visit[pp.first])
        continue;

      pq.push({-pp.second, pp.first});
    }
  }

  cout << cost;
}
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> S[32001];
int indegree[32001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M;
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    S[A].push_back(B);
    indegree[B]++;
  }

  queue<int> q;

  for (int i = 1; i <= N; i++) {
    if (indegree[i] == 0)
      q.push(i);
  }

  while (!q.empty()) {
    auto v = q.front();
    q.pop();

    cout << v << '\n';

    for (auto d : S[v]) {
      indegree[d] -= 1;
      if (indegree[d] == 0) {
        q.push(d);
      }
    }
  }
}

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int UF[10001];

void UF_init() {
  for (int i = 0; i < 10001; i++)
    UF[i] = i;
}

int UF_find(int i) {
  if (UF[i] == i)
    return i;
  return UF[i] = UF_find(UF[i]);
}

void UF_union(int i, int j) {
  int ii = UF_find(i);
  int jj = UF_find(j);

  if (ii > jj)
    swap(ii, jj);

  UF[jj] = ii;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  UF_init();

  int V, E;
  cin >> V >> E;

  priority_queue<pair<int, pair<int, int>>> pq;

  for (int i = 0; i < E; i++) {
    int A, B, C;
    cin >> A >> B >> C;

    pq.push({-C, {A, B}});
  }

  long long w = 0;

  while (!pq.empty()) {
    auto p = pq.top();
    pq.pop();

    if (UF_find(p.second.first) == UF_find(p.second.second))
      continue;

    w += p.first;

    UF_union(p.second.first, p.second.second);
  }

  cout << -w;
}
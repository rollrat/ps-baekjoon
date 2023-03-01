#include <iostream>

using namespace std;

int map[501][501];
int N, M, B;

long long test(int dest_depth) {
  long long cost = 0;
  long long remainB = B;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (map[i][j] < dest_depth) {
        cost += dest_depth - map[i][j];
        remainB -= dest_depth - map[i][j];
      } else if (map[i][j] > dest_depth) {
        cost += (map[i][j] - dest_depth) * 2;
        remainB += map[i][j] - dest_depth;
      }
    }
  }

  if (remainB < 0)
    return -1;

  return cost;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M >> B;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> map[i][j];
    }
  }

  long long min_cost = 0x7fffffffffffffff;
  int max_depth = 0;

  for (int i = 0; i <= 256; i++) {
    auto r = test(i);

    if (r >= 0 && min_cost >= r) {
      min_cost = r;
      max_depth = i;
    }
  }

  cout << min_cost << ' ' << max_depth;
}
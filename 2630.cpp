#include <iostream>

using namespace std;

int map[129][129] = {0};

struct CostResult {
  int w, b;
  CostResult(int w, int b) : w(w), b(b) {}

  CostResult operator+(const CostResult &r) {
    return CostResult(w + r.w, b + r.b);
  }
};

CostResult calCost(int N, int r, int c) {
  // check all component is zero or one

  int p = map[r][c];
  bool mustSplit = false;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (p != map[r + i][c + j]) {
        mustSplit = true;
        break;
      }
    }

    if (mustSplit)
      break;
  }

  if (!mustSplit) {
    if (map[r][c] == 0)
      return CostResult(1, 0);
    else
      return CostResult(0, 1);
  }

  return calCost(N / 2, r, c) + calCost(N / 2, r + N / 2, c) +
         calCost(N / 2, r, c + N / 2) + calCost(N / 2, r + N / 2, c + N / 2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> map[i][j];
    }
  }

  auto r = calCost(N, 0, 0);

  cout << r.w << '\n' << r.b;
}
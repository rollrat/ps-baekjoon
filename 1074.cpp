#include <iostream>

using namespace std;

/*

  return 0~3

   0     | 1
  ---------------
   2     | 3

*/
int getPosition(int N, int r, int c) {
  if (c < N / 2) {
    if (r < N / 2) {
      return 0;
    }
    return 2;
  }
  if (r < N / 2) {
    return 1;
  }
  return 3;
}

int main() {
  int N, r, c;

  cin >> N >> r >> c;

  int stepSave[100] = {0};
  int stepPoint = 0;

  int result = 0;

  for (int i = 1 << N; i >= 2;) {
    int p = getPosition(i, r, c);
    stepSave[stepPoint++] = p;

    if (p & 1) {
      c -= i / 2;
    }

    if (p >= 2) {
      r -= i / 2;
    }

    result += i * i / 4 * p;

    i /= 2;
  }

  cout << result << '\n';
}
#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;

  long long P[101];

  P[0] = P[1] = P[2] = 1;
  P[3] = P[4] = 2;

  for (int i = 5; i < 101; i++) {
    P[i] = P[i - 1] + P[i - 5];
  }

  while (T--) {
    int N;
    cin >> N;

    cout << P[N - 1] << '\n';
  }
}
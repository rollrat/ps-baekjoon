#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, K;
  cin >> N >> K;

  queue<int> q;
  int acc = 0;
  int acc_max = -0x7fffffff;

  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;

    q.push(x);
    acc += x;

    if (q.size() == K) {
      acc_max = max(acc_max, acc);
      acc -= q.front();
      q.pop();
    }
  }

  acc_max = max(acc_max, acc);

  cout << acc_max;
}
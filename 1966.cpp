#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    int N, Q;
    cin >> N >> Q;

    priority_queue<int> pq;
    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++) {
      int n;
      cin >> n;
      pq.push(n);
      q.push({n, i});
    }

    int print_count = 0;

    while (!q.empty()) {
      if (q.front().first < pq.top()) {
        q.push(q.front());
        q.pop();
      } else {
        if (q.front().second == Q) {
          cout << print_count + 1 << '\n';
          break;
        }

        q.pop();
        pq.pop();
        print_count++;
      }
    }
  }
}
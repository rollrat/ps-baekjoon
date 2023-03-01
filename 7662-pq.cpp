#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    int k;
    cin >> k;

    priority_queue<int> pq_max;
    priority_queue<int, vector<int>, greater<int>> pq_min;
    map<int, int> mmap;

    while (k--) {
      char op;
      int n;
      cin >> op >> n;

      if (op == 'I') {
        if (mmap.find(n) == mmap.end())
          mmap[n] = 0;
        mmap[n] += 1;

        pq_max.push(n);
        pq_min.push(n);
      } else {
        if (n == -1) {
          while (!pq_min.empty()) {
            auto t = pq_min.top();
            pq_min.pop();

            if (mmap[t] > 0) {
              mmap[t] -= 1;
              break;
            }
          }
        } else {
          while (!pq_max.empty()) {
            auto t = pq_max.top();
            pq_max.pop();

            if (mmap[t] > 0) {
              mmap[t] -= 1;
              break;
            }
          }
        }
      }
    }

    bool find_min = false;
    int min_value;

    while (!pq_min.empty()) {
      auto t = pq_min.top();
      pq_min.pop();

      if (mmap[t] > 0) {
        mmap[t] -= 1;
        find_min = true;
        min_value = t;
        break;
      }
    }

    bool find_max = false;
    int max_value;

    while (!pq_max.empty()) {
      auto t = pq_max.top();
      pq_max.pop();

      if (mmap[t] > 0) {
        mmap[t] -= 1;
        find_max = true;
        max_value = t;
        break;
      }
    }

    if (find_min || find_max) {
      if (find_max == false) {
        cout << min_value << ' ' << min_value << '\n';
      } else if (find_min == false) {
        cout << max_value << ' ' << max_value << '\n';
      } else {
        cout << max_value << ' ' << min_value << '\n';
      }
    } else {
      cout << "EMPTY\n";
    }
  }
}
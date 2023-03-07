#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  set<int> s;
  vector<int> v;
  vector<int> origin;
  v.reserve(N);
  origin.reserve(N);

  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;

    if (s.find(x) == s.end()) {
      s.insert(x);
      v.push_back(x);
    }

    origin.push_back(x);
  }

  sort(v.begin(), v.end());

  for (auto x : origin) {
    cout << lower_bound(v.begin(), v.end(), x) - v.begin() << ' ';
  }
}
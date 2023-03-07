#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  vector<int> v;
  vector<int> origin;
  vector<int> r(N);
  v.reserve(N);
  origin.reserve(N);

  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;

    v.push_back(i);
    origin.push_back(x);
  }

  sort(v.begin(), v.end(), [&](int i, int j) { return origin[i] < origin[j]; });

  r[v[0]] = 0;

  for (int i = 1; i < N; i++) {
    r[v[i]] = r[v[i - 1]];
    if (origin[v[i]] != origin[v[i - 1]])
      r[v[i]]++;
  }

  for (auto x : r) {
    cout << x << ' ';
  }
}
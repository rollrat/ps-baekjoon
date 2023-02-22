#include <iostream>
#include <queue>

using namespace std;

int arr[10000000];

void do_sort(int N) {
  queue<int> q[256];

  for (int i = 0; i < 4; i++) {
    int mask = 0xff << (i * 8);

    for (int j = 0; j < N; j++) {
      int mask_value = (arr[j] >> (i * 8)) & 0xff;
      q[mask_value].push(arr[j]);
    }

    int arr_index = 0;

    for (int j = 0; j < 256; j++) {
      while (!q[j].empty()) {
        auto v = q[j].front();
        q[j].pop();
        arr[arr_index++] = v;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    arr[i] += 1001;
  }

  do_sort(N);

  for (int i = 0; i < N; i++) {
    cout << arr[i] - 1001 << '\n';
  }
}

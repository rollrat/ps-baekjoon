#include <iostream>
#include <vector>

using namespace std;

int arr[1001];

void do_sort(int N) {

  vector<int> buf(N), cnt(256), idx(256);

  int *org = &arr[0], *des = &buf[0];

  for (int i = 0; i < 4; i++, swap(org, des)) {
    fill(cnt.begin(), cnt.end(), 0);

    for (int j = 0; j < N; j++) {
      cnt[(org[j] >> (i << 3)) & 0xff]++;
    }

    idx[0] = 0;
    for (int j = 1; j < 256; j++) {
      idx[j] = idx[j - 1] + cnt[j - 1];
    }

    for (int j = 0; j < N; j++) {
      des[idx[(org[j] >> (i << 3)) & 0xff]++] = org[j];
    }
  }

  copy(buf.begin(), buf.end(), arr);
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

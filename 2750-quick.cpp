#include <iostream>

using namespace std;

int arr[1001];

void sort_internal(int s, int e) {
  if (s >= e)
    return;

  int pivot = arr[s];
  int l = s + 1, h = e;

  while (l <= h) {
    while (l <= e && arr[l] < pivot)
      l++;

    while (s < h && arr[h] > pivot)
      h--;

    if (l <= h) {
      swap(arr[l], arr[h]);
    } else {
      swap(arr[h], arr[s]);
    }
  }

  sort_internal(s, h - 1);
  sort_internal(h + 1, e);
}

void do_sort(int N) { sort_internal(0, N - 1); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++)
    cin >> arr[i];

  do_sort(N);

  for (int i = 0; i < N; i++) {
    cout << arr[i] << '\n';
  }
}

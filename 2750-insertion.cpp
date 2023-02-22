#include <iostream>

using namespace std;

int arr[1001];

void do_sort(int N) {
  for (int i = 1; i < N; i++) {
    int x = arr[i];
    int j = i - 1;

    for (; j >= 0 && arr[j] > x; j--) {
      arr[j + 1] = arr[j];
    }

    arr[j + 1] = x;
  }
}

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

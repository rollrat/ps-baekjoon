#include <iostream>

using namespace std;

int arr[1001];

void do_sort(int N) {
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      if (arr[i] > arr[j])
        swap(arr[i], arr[j]);
    }
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

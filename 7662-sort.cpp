#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int arr[1000000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    int k;
    cin >> k;

    int i = 0, j = 0;

    while (k--) {
      char op;
      int n;
      cin >> op >> n;

      if (op == 'I') {
        arr[j] = n;
        j++;
        sort(arr + i, arr + j);
      } else if (op == 'D') {
        if (i == j)
          continue;

        if (n == -1) {
          i++;
        } else if (n == 1) {
          j--;
        }
      }
    }

    if (i == j)
      cout << "EMPTY\n";
    else {
      cout << arr[j - 1] << ' ' << arr[i];
    }
  }
}
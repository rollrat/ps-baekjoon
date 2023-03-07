#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int x = 0, x1 = 2, x2 = 1;

  if (n == 1) {
    cout << "1\n";
    return 0;
  } else if (n == 2) {
    cout << "2\n";
    return 0;
  }

  for (int i = 0; i < n - 2; i++) {
    x = (x1 + x2) % 10007;
    x2 = x1;
    x1 = x;
  }

  cout << x;
}
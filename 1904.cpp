#include <iostream>

using namespace std;

int fib[1000001];

int gfib(int n) {
  fib[1] = fib[2] = 1;

  for (int i = 3; i <= n; i++) {
    fib[i] = (fib[i - 1] + fib[i - 2]) % 15746;
  }

  return fib[n];
}

int main() {
  int N;
  cin >> N;

  cout << gfib(N + 1);
}
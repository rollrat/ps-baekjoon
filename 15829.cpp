#include <iostream>
#include <string>

using namespace std;

int main() {
  int L;
  string s;
  cin >> L >> s;

  long long H = 0;
  long long r = 1;
  const long long M = 1234567891;

  for (auto c : s) {
    int a = c - 'a' + 1;
    H = (H + ((a * r) % M)) % M;
    r = (r * 31) % M;
  }

  cout << H;
}
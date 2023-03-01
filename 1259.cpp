#include <iostream>
#include <string>

using namespace std;

int main() {
  while (true) {
    string s;
    cin >> s;

    if (s == "0")
      break;

    for (int i = 0; i < s.length() / 2; i++) {
      if (s[i] != s[s.length() - i - 1]) {
        cout << "no\n";
        goto END;
      }
    }

    cout << "yes\n";

  END:;
  }
}
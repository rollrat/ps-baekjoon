#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  while (getline(cin, s)) {
    if (s == ".")
      break;

    stack<char> stk;
    bool fail = false;

    for (auto c : s) {
      if (c == '(' || c == '[') {
        stk.push(c);
      } else if (c == ')') {
        if (stk.size() == 0 || stk.top() != '(') {
          fail = true;
          break;
        }

        stk.pop();
      } else if (c == ']') {
        if (stk.size() == 0 || stk.top() != '[') {
          fail = true;
          break;
        }

        stk.pop();
      }
    }

    cout << (fail || stk.size() > 0 ? "no" : "yes") << '\n';
  }
}